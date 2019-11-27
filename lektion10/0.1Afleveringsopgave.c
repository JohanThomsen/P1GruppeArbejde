#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void Partition_String(char string[], int size_Of_Array, char *Warehouse, char *ID, char *Qualifier);

int main(void)
{
    int i;
    char string[] = "ATAT4560S43";
    int size_Of_Array;
    char Warehouse[12];
    char ID[12];
    char Qualifier[12];

    size_Of_Array = strlen(string);

   

    memset(Warehouse, '\0', sizeof(Warehouse));
    memset(ID, '\0', sizeof(ID));
    memset(Qualifier, '\0', sizeof(Qualifier));


    Partition_String(string, size_Of_Array, Warehouse, ID, Qualifier);

    return 0;
}

void Partition_String(char string[], int size_Of_Array, char *Warehouse, char *ID, char *Qualifier){

    int i;
    int warehouse_check = 0;
    int ID_Check = 0;
    int qualifier_Check = 0;

    printf("%s\n", Warehouse);

    for (i = 0; i <= size_Of_Array; ++i)
    {
        if (isdigit(string[i]) && warehouse_check != 0)
        {
            strncpy(Warehouse, string, i);
            warehouse_check = i;
        }
    }

    

}