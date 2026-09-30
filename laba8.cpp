#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <io.h>
#include <string.h>

struct TStud {
    char FIO[30];
    int year;
    int group;
    int phys;
    int math;
    int inf;
    int chem;
    double avg;
} Stud;

int size = sizeof(TStud);

FILE* Fz, * Ft;
char File_Zap[] = "students.dat";
char File_Rez[] = "result.txt";

void Out(TStud z);

void ReadString(char* s, int max) {
    fflush(stdin);
    fgets(s, max, stdin);
    int len = strlen(s);
    if (len > 0 && s[len - 1] == '\n')
        s[len - 1] = '\0';
}

int main() {
    int kod;
    int D_f, kol;
    long len;

    Ft = fopen(File_Rez, "w");
    if (!Ft) return 0;

    while (1) {
        puts("\n 1 - Create");
        puts(" 2 - View");
        puts(" 3 - Correct");
        puts(" 4 - Task 16");
        puts(" 0 - Exit");
        printf(" Input code: ");
        if (scanf("%d", &kod) != 1) return 0;

        switch (kod) {

        case 1: {
            Fz = fopen(File_Zap, "wb");
            if (!Fz) { puts("Create ERROR!"); break; }
            fclose(Fz);
            puts("Created.");
            break;
        }

        case 2: {
            Fz = fopen(File_Zap, "rb");
            if (!Fz) { puts("Open ERROR!"); break; }

            puts("\n--- All students ---");
            while (fread(&Stud, size, 1, Fz))
                Out(Stud);

            fclose(Fz);
            break;
        }

        case 3: {
            int mode;
            printf("\n 1 - Add\n 2 - Edit\n Mode: ");
            scanf("%d", &mode);

            if (mode == 1) {
                Fz = fopen(File_Zap, "ab");
                if (!Fz) break;

                printf(" FIO: ");
                ReadString(Stud.FIO, 30);

                printf(" Year: "); scanf("%d", &Stud.year);
                printf(" Group: "); scanf("%d", &Stud.group);
                printf(" Physics: "); scanf("%d", &Stud.phys);
                printf(" Math: "); scanf("%d", &Stud.math);
                printf(" Inf: "); scanf("%d", &Stud.inf);
                printf(" Chem: "); scanf("%d", &Stud.chem);

                Stud.avg = (Stud.phys + Stud.math + Stud.inf + Stud.chem) / 4.0;

                fwrite(&Stud, size, 1, Fz);
                fclose(Fz);
            }

            else if (mode == 2) {
                Fz = fopen(File_Zap, "rb+");
                if (!Fz) break;

                D_f = _fileno(Fz);
                len = _filelength(D_f);
                kol = len / size;

                int num;
                printf(" Records: %d\n Number: ", kol);
                scanf("%d", &num);

                fseek(Fz, (num - 1) * size, SEEK_SET);
                fread(&Stud, size, 1, Fz);

                printf("New FIO: ");
                ReadString(Stud.FIO, 30);

                printf(" Year: "); scanf("%d", &Stud.year);
                printf(" Group: "); scanf("%d", &Stud.group);
                printf(" Physics: "); scanf("%d", &Stud.phys);
                printf(" Math: "); scanf("%d", &Stud.math);
                printf(" Inf: "); scanf("%d", &Stud.inf);
                printf(" Chem: "); scanf("%d", &Stud.chem);

                Stud.avg = (Stud.phys + Stud.math + Stud.inf + Stud.chem) / 4.0;

                fseek(Fz, (num - 1) * size, SEEK_SET);
                fwrite(&Stud, size, 1, Fz);

                fclose(Fz);
            }
            break;
        }

        case 4: {
            int g;
            printf("Input group: ");
            scanf("%d", &g);

            Fz = fopen(File_Zap, "rb");
            if (!Fz) break;

            puts("\n--- Task 16 ---");

            int found = 0;

            while (fread(&Stud, size, 1, Fz)) {
                if (Stud.group == g && Stud.phys == 8 && Stud.math == 9) {
                    Out(Stud);
                    found = 1;
                }
            }
            if (!found) puts("No students.");

            fclose(Fz);
            break;
        }

        case 0:
            fclose(Ft);
            return 0;
        }
    }
}

void Out(TStud z) {
    printf("\n %20s  %4d  %4d  %2d %2d %2d %2d   %.2lf",
        z.FIO, z.year, z.group, z.phys, z.math, z.inf, z.chem, z.avg);
}
