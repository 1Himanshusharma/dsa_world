#include<stdio.h>

int main() {
  int distance;
  printf("Please enter your distance: ");
  scanf("%d", &distance);

  int ans = ((distance < 500) ? ((distance < 200) ? (0.40 * distance) : (0.35 * distance)) : (0.30 * distance));
  int final_ans = ans - (ans * 0.05);
  printf("ans: %d",final_ans);


}
