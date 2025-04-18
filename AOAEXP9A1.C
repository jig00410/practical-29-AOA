#include <stdio.h>
#include <stdlib.h>

#define MAX 100

static int total_nodes;

void printValues(int A[], int size) {
   int i;
   for (i = 0; i < size; i++) {
      printf("%5d", A[i]);
   }
   printf("\n");
}

void subset_sum(int s[], int t[], int s_size, int t_size, int sum, int ite, int target_sum) {
   int i;
   total_nodes++;
   if (target_sum == sum) {
      printValues(t, t_size);
      subset_sum(s, t, s_size, t_size - 1, sum - s[ite], ite + 1, target_sum);
      return;
   } else {
      for (i = ite; i < s_size; i++) {
         t[t_size] = s[i];
         subset_sum(s, t, s_size, t_size + 1, sum + s[i], i + 1, target_sum);
      }
   }
}

void generateSubsets(int s[], int size, int target_sum) {
   int tuplet_vector[MAX]; // Avoid malloc
   subset_sum(s, tuplet_vector, size, 0, 0, 0, target_sum);
}

int main() {
   int set[] = { 5, 6, 12, 54, 2, 20, 15 };
   int size = sizeof(set) / sizeof(set[0]);

   printf("The set is: ");
   printValues(set, size);

   generateSubsets(set, size, 25);

   printf("Total Nodes generated: %d\n", total_nodes);
   return 0;
}
