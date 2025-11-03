#include "ICharacter.hpp"
#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

// int main(void)
// {
// 	IMateriaSource* src = new MateriaSource();
// 	src->learnMateria(new Ice());
// 	src->learnMateria(new Cure());
// 	ICharacter* me = new Character("me");
// 	AMateria* tmp;
// 	tmp = src->createMateria("ice");
// 	me->equip(tmp);
// 	tmp = src->createMateria("cure");
// 	me->equip(tmp);
// 	ICharacter* bob = new Character("bob");
// 	me->use(0, *bob);
// 	me->use(1, *bob);
// 	delete bob;
// 	delete me;
// 	delete src;
// 	return 0;
// }


static void banner(const char* title) {
    std::cout << "\n========== " << title << " ==========\n";
}

int main() {
    // 1) MateriaSource にテンプレ(ひな型)を学習させる
    banner("SETUP: learnMateria(ice, cure)");
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());   // ← learnMateriaはcloneして内部保存する設計
    src->learnMateria(new Cure());

    // 2) キャラクター作成
    ICharacter* me  = new Character("me");
    ICharacter* bob = new Character("bob");

    // 3) createMateria → equip → use（基本動作）
    banner("BASIC: create -> equip -> use");
    AMateria* m1 = src->createMateria("ice");
    AMateria* m2 = src->createMateria("cure");
    me->equip(m1);     // 所有権は me へ移動（me のデストラクタで delete される前提）
    me->equip(m2);
    me->use(0, *bob);  // ice
    me->use(1, *bob);  // cure
	me->use(8,*bob);

    // 4) 未知タイプの生成テスト（NULLが返るべき）
    banner("EDGE: unknown type returns NULL");
    AMateria* mx = src->createMateria("fire");
    if (mx == 0) std::cout << "OK: createMateria(\"fire\") returned NULL\n";
    else {
        std::cout << "NG: createMateria(\"fire\") should return NULL\n";
        delete mx; // 念のため後始末
    }

    // 5) インベントリ満杯テスト（4つまで）+ 5個目の装備は失敗 (何も起きない)
    banner("EDGE: full inventory & safe cleanup of extra");
    AMateria* m3 = src->createMateria("ice");
    AMateria* m4 = src->createMateria("cure");
    me->equip(m3);
    me->equip(m4);
    me->use(2, *bob);
    me->use(3, *bob);

    // 5個目（満杯なので equip は何も起きない= me は所有しない → 呼び出し側で delete）
    AMateria* m5_extra = src->createMateria("ice");
    me->equip(m5_extra);            // 仕様どおりなら何も起きない（装備されない）
    // ★ ここでリークを避けるために必ず後始末（所有権は me に移っていない想定）
    delete m5_extra;

    // 6) out-of-range / 空スロットuse（何も起きない）
    banner("EDGE: out-of-range and empty use must be no-op");
    me->use(-1, *bob);              // 何も起きない
    me->use(42, *bob);              // 何も起きない

    // 7) 深いコピーの確認（Character: copy-ctor）
    banner("DEEP COPY: Character copy-ctor");
    Character cpyMe(*(Character*)me);   // ICharacter から具象へキャストしてコピー
    cpyMe.use(0, *bob);                 // 動くはず（独立なクローンを保持）
    cpyMe.use(1, *bob);

    // 8) 深いコピーの確認（Character: operator=）
    banner("DEEP COPY: Character operator=");
    Character assignTarget("assignTarget");
    assignTarget = *(Character*)me;
    assignTarget.use(2, *bob);
    assignTarget.use(3, *bob);

    // 9) MateriaSource の深いコピー（テンプレがクローンされるか）
    banner("DEEP COPY: MateriaSource copy & assign");
    MateriaSource srcCopy(*(MateriaSource*)src);       // copy-ctor
    AMateria* c1 = srcCopy.createMateria("ice");
    if (c1) {
        std::cout << "OK: srcCopy can create 'ice' (template cloned)\n";
        delete c1; // 使い終わったので delete（所有権は呼び出し側）
    } else {
        std::cout << "NG: srcCopy failed to create 'ice'\n";
    }

    MateriaSource srcAssign;
    srcAssign = *(MateriaSource*)src;                  // operator=
    AMateria* c2 = srcAssign.createMateria("cure");
    if (c2) {
        std::cout << "OK: srcAssign can create 'cure' (template cloned)\n";
        delete c2;
    } else {
        std::cout << "NG: srcAssign failed to create 'cure'\n";
    }

    // 10) 片付け（所有権の整合に注意）
    banner("CLEANUP");
    delete bob;  // 何も所有していないはず
    delete me;   // インベントリ4枠は ~Character() で delete される想定
    delete src;  // テンプレ4枠は ~MateriaSource() で delete される想定

    banner("END");
    return 0;
}