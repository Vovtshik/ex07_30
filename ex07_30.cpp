/*ex07_30.cpp*/

#include <iostream>
using std::cout;
using std::endl;

void bucketSort(int[], int, int arr2[][15]);
void showArr(int[], int);

int main()
{
   const int number = 15;
   int arr1[number] = {11, 25, 2, 15, 9, 4, 14, 13, 1, 8, 33, 12, 6, 71, 10};
   int arr2[10][number];

   cout << "Array of integers before sorting:\n";
   showArr(arr1, 15);

   for(int i = 0; i < 10; i++)
   {
      for(int j = 0; j < number; j++)
      {
         arr2[i][j] = -1;
      }
   }

   bucketSort(arr1, number, arr2);

   cout << "Array of integers after sorting:\n";
   showArr(arr1, 15);

   return 0;
}

void bucketSort(int arr1[], int num, int arr2[][15])
{
   int number_rank = 10;

   int temp;

   while (number_rank < 101)
   {
       for (int i = 0; i < 10; i++)
       {
           temp = 0;
           for (int j = 0; j < num; j++)
           {
               if (i == ( (arr1[j] % number_rank) - ( arr1[j] % (number_rank / 10) ) ) / (number_rank / 10) )
               {
                   arr2[i][temp] = arr1[j];
                   temp++;
               }
           }
       }

       temp = 0;

       for (int i = 0; i < 10; i++)
       {
           for (int j = 0; j < num; j++)
           {
               if (arr2[i][j] == -1)
                   break;
               else
               {
                   arr1[temp] = arr2[i][j];
                   temp++;
               }
           }
       }

       for (int i = 0; i < 10; i++)
       {
           for (int j = 0; j < num; j++)
           {
               arr2[i][j] = -1;
           }
       }
       number_rank *= 10;
   }
}

void showArr(int arr1[], int num)
{
   for(int s = 0; s < num; s++)

   {
      cout << arr1[s] << " ";
   }
   cout << endl << endl;
}
