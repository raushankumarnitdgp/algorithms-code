#include <stdio.h>
using namespace std;
#define SUITS 4
#define FACES 13
#define FALSE 0
#define TRUE  1
int straight,flush,four,three;
int pairs;

int suitsInHand[SUITS];
int facesInHand[FACES];


void analyzeHand()
{
      int num_consec = 0;
      int rank, suit;
      straight = FALSE;
      flush = FALSE;
      four = FALSE;
      three = FALSE;
      pairs = 0;
      // check for flush – 5 cards of the same suit
      for (suit = 0; suit < SUITS; suit++)
            if (suitsInHand[suit] == 5)
                  flush = TRUE;
      // check for straight – eg. One each of 5,6,7,8,9
      //    locate the first card
      rank = 0;
      while (facesInHand[rank] == 0)
            rank++;
      //     count the consecutive non-zero faces
      for (; rank < FACES && facesInHand[rank]; rank++)
            num_consec++;
      if (num_consec == 5) {
            straight = TRUE;
            return;
      }
      /* check for 4-of-a-kind, 3-of-a-kind, and pairs */
      for (rank = 0; rank < NUM_RANKS; rank++) {
            if (facesInHand[rank] == 4)
                  four = TRUE;
            if (facesInHand[rank] == 3)
                  three = TRUE;
            if (facesInHand[rank] == 2)
                  pairs++;
      }
}




int main()
{
  //intialize the array
  for(int i=0;i<SUITS;i++)
    suitsInHand[i]=0;
  for(int i=0;i<FACES;i++)
    facesInHand[i]=0;
  
  //input
  for(int i=0;i<SUITS;i++)
    cin>>suitsInHand[i];
  for(int i=0;i<FACES;i++)
    cin>>facesInHand[i];
  
  analyzeHand();
  
      if (straight && flush)
            printf("Straight flush\n\n");
      else if (four)        
            printf("Four of a kind\n\n");
      else if (three && pairs == 1)  
            printf("Full house\n\n");
      else if (flush)       
            printf("Flush\n\n");
      else if (straight)    
            printf("Straight\n\n");
      else if (three)       
            printf("Three of a kind\n\n");
      else if (pairs == 2)  
            printf("Two pairs\n\n");
      else if (pairs == 1)  
            printf("Pair\n\n");
      else                  
            printf("High card\n\n");
  
  
  return 0;
}