#include "../Function/ADT/Tree/tree.h"
#include "../Function/ADT/mesinkata.h"
#include <stdio.h>

void printCabang(BinTree P){
    if (!IsTreeEmpty(P)){
        printf("%d ", P->Info); 
    }
    else{
        printf("    ");
    }
}

void printPohon(BinTree T){
    BinTree a, b, c, d;
    a = T;
    b = T;
    c = T;
    d = T;
    if (IsTreeEmpty(T)){
        printf("TREE KOSONG\n");
    }
    else{
        printf("    ");
        printf("%d", a->Info);
        printf("\n");
        a = Left(a);
        b = Left(b);
        c = Right(c);
        d = Right(d);
        printf("  ");
        printCabang(a);
        printCabang(c);
        printf("\n");
        if (!IsTreeEmpty(a)){
            a = Left(a);
            b = Right(b);
            printCabang(a);
            printCabang(b);
        }
        else{
            printf("    ");
        }
        if (!IsTreeEmpty(c)){
            c = Left(c);
            d = Right(d);
            printCabang(c);
            printCabang(d);
        }
    }
    printf("\n");
}

int main(){
    printf("==== DRIVER ADT BINTREE ====\n");
    printf("Berisi fungsi-fungsi untuk ADT BINTREE\n");

    //KAMUS
    BinTree T1, T2; 

    printf("==== Tree ====\n");
    T1 = Tree(99, NilTree, NilTree);
    printf("EKSPEKTASI : return suatu Tree dengan nilai root, dan cabang yang ditentukan\n");
    printf("TEST : Fungsi Tree digunakan untuk membuat Tree satu element bernilai 99\n");
    printf("TREE T1 : \n");
    printPohon(T1);

    printf("==== MakeTree ====\n");
    MakeTree(10, Tree(20, NilTree, NilTree), Tree(30, NilTree, NilTree), &T2);
    printf("EKSPEKTASI : modifikasi suatu variabel tree terdefinisii sehingga memiliki nilai root dan cabang yang ditentukan\n");
    printf("TEST : Fungsi Tree digunakan untuk membuat Tree dengan root bernilai 10\ndan dua cabang bernilai 20 dan 30\n");
    printf("TREE T2 : \n");
    printPohon(T2);
    printf("\n");

    printf("==== isTreeEmpty ====\n");
    printf("EKSPEKTASI : bernilai 1 jika tree kosong, 0 jika tidak\n");
    printf("TEST : Testing menggunakan T1 dan Left(T1)\n");
    printf("isTreeEmpty - T1 : %d\n", IsTreeEmpty(T1));
    printf("isTreeEmpty - Left(T1) : %d\n", IsTreeEmpty(Left(T1)));
    printf("\n");

    printf("==== IsOneElmt ====\n");
    printf("EKSPEKTASI : bernilai 1 jika adalah satu element, 0 jika tidak\n");
    printf("TEST : Testing menggunakan T1 dan T2\n");
    printf("isOneElmt - T1 : %d\n", IsOneElmt(T1));
    printf("isOneElmt - T2 : %d\n", IsOneElmt(T2));
    printf("\n");

    printf("==== addDaun ====\n");
    printf("EKSPETASI : Menambahkan daun di posisi yang ditentukan\n");
    printf("TEST : Menambahkan daun bernilai 12 di sisi kiri T1\n");
    AddDaun(&T1, 99, 12, true);
    printPohon(T1);

    printf("==== DelDaun ====\n");
    printf("EKSPEKTASI : menghapus daun bernilai X\n");
    printf("TEST : Menghapus daun T2 yang bernilai 20\n");
    DelDaun(&T2, 20);
    printPohon(T2);


    printf("==== IsUnerLeft ====\n");
    printf("EKSPEKTASI : bernilai 1 jika pohon adalah Uner Left, 0 jika tidak\n");
    printf("TEST : Testing menggunakan T1 dan T2\n");
    printf("IsUnerLeft - T1 : %d\n", IsUnerLeft(T1));
    printf("IsUnerLeft - T2 : %d\n", IsUnerLeft(T2));
    printf("\n");

    printf("==== IsUnerRight ====\n");
    printf("EKSPEKTASI : bernilai 1 jika pohon adalah UnerRight, 0 jika tidak\n");
    printf("TEST : Testing menggunakan T1 dan T2\n");
    printf("IsUnerRight - T1 : %d\n", IsUnerRight(T1));
    printf("IsUnerRight - T2 : %d\n", IsUnerRight(T2));
    printf("\n");

    printf("Untuk Testing Selanjutnya T2 ditambahkan kembali\ncabang kirinya bernilai 20\n");
    AddDaun(&T2, 10, 20, true);
    printPohon(T2);

    printf("==== IsBiner ====\n");
    printf("EKSPEKTASI : bernilai 1 jika pohon adalah Biner, 0 jika tidak\n");
    printf("TEST : Testing menggunakan T1 dan T2\n");
    printf("IsBiner - T1 : %d\n", IsBiner(T1));
    printf("IsBiner - T2 : %d\n", IsBiner(T2));
    printf("\n");

    printf("==== SearchTree ====\n");
    printf("EKSPEKTASI : bernilai 1 jika adalah elemen terdapat dalam tree, 0 jika tidak\n");
    printf("TEST : Testing menggunakan T1 dan T2 dengan elemen bernilai 20\n");
    printf("SearchTree(T1, 20): %d\n", IsBiner(T1));
    printf("IsBiner(T2, 20) : %d\n", IsBiner(T2));
    printf("\n");

    printf("==== NbElmt ====\n");
    printf("EKSPEKTASI : mengembalikan jumlah elemen\n");
    printf("TEST : Testing menggunakan T1 dan T2\n");
    printf("NbElmt - T1: %d\n", NbElmt(T1));
    printf("NbElmt - T2: %d\n", NbElmt(T2));
    printf("\n");

    printf("==== NbDaun ====\n");
    printf("EKSPEKTASI : mengembalikan jumlah daun\n");
    printf("TEST : Testing menggunakan T1 dan T2\n");
    printf("NbDaun - T1: %d\n", NbDaun(T1));
    printf("NbDaun - T2: %d\n", NbDaun(T2));
    printf("\n");

    printf("==== IsSkewLeft ====\n");
    printf("EKSPEKTASI : bernilai 1 jika pohon adalah Skew Left, 0 jika tidak\n");
    printf("TEST : Testing menggunakan T1 dan T2\n");
    printf("IsSkewLeft - T1: %d\n", IsSkewLeft(T1));
    printf("IsSkewLeft - T2: %d\n", IsSkewLeft(T2));
    printf("\n");
    
    printf("==== IsSkewRight ====\n");
    printf("EKSPEKTASI : bernilai 1 jika pohon adalah Skew Right, 0 jika tidak\n");
    printf("TEST : Testing menggunakan T1 dan T2\n");
    printf("Untuk Testing Selanjutnya T2 menghapus cabang kirinya sehingga menjadi\npohon biner yang skewright\n");
    DelDaun(&T2, 20);
    printPohon(T2);
    printf("IsSkewRight - T1: %d\n", IsSkewRight(T1));
    printf("IsSkewRight - T2: %d\n", IsSkewRight(T2));
    printf("\n");

    printf("==== addDaunTerkiri ====\n");
    printf("EKSPETASI : bertambah simpulnya, dengan X sebagai simpul daun terkiri\n");
    printf("TEST : Menambahkan Daun bernilai 10 pada T2 dengan addDaunTerkiri\n");
    AddDaunTerkiri(&T2, 10);
    printPohon(T2);

    printf("==== DelDaunTerkiri ====\n");
    printf("EKSPETASI : dihapus daun terkirinya, dan didealokasi, dengan X adalah info yang \nsemula disimpan pada daun terkiri yang dihapus\n");
    printf("TEST : Menghapus daun terkiri dari T2\n");
    int X;
    DelDaunTerkiri(&T2, &X);
    printf("nilai X : %d\n", X);
    printPohon(T2);


    return 0; 
}