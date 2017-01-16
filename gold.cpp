#include <iostream>
#include <chrono>
#include <random>
#include <map>
#include <vector>
 
using namespace std;
 
 
class RandomNumberGenerator {
public:
    RandomNumberGenerator(int x) :generator(x) {};
    // return a double between -1 and 1
    double randomBetween1and2() {
        return (2.0*generator()) / generator.max() - 1.0;
    }
private:
    minstd_rand0 generator;
};
 
 
int N;
// Use a constant random number seed so behavior is consistent from run to run.
int RANDOM_SEED;
 
int main()
{
    
    cout << "Enter seed for random number generator: ";
    cin >> RANDOM_SEED;
    RandomNumberGenerator rng(RANDOM_SEED);
    
    cout << "Enter number of leprechauns: ";
    cin >> N;
    
    long playtime;
    cout << "Enter game play time (seconds): ";
    cin >> playtime;
    playtime = playtime * 1000; // convert to milliseconds
    
    double score = 0;
    int nTrapped = 0;
    // CODE FOR INITIALIZING DATA STRUCTURES GOES HERE
    multimap<int, int> DataStructure;
    int gold = 1000000;
    for (int i = 0; i < N; i++)
    {
        //Create N-locations based on the ammount of leprechauns.
        //Key: Location Value: What leprachaun is present.
        double location = i * gold;
        DataStructure.insert(make_pair(location, i + 1));
    }
    //Iterator to traverse around leprechauns:
    
    //Vector for Gold:
    //Creates N ints with default value of gold(1mil)
    vector<double>LeprachaunGold(N,gold);
    
    int t = 0; // keep track of number of iterations
    auto start_time0 = chrono::high_resolution_clock::now();
    auto timeSinceStartMS = 0;
    do {
        // CODE FOR A SINGLE ITERATION GOES HERE
        
        //Iteration - Traverse through the data structure:
        for (std::multimap<int,int>::iterator it=DataStructure.begin(); it!=DataStructure.end(); ++it)
        {
            int vectorIterator = 0;
            //1 The leprechaun jumps to a new location.
            //// You can use the random number generator like so:
            double r = rng.randomBetween1and2();
            double x = 0;
            x = x + r*gold;
            DataStructure.insert(make_pair(x, (*it).second));
            //Delete old location.
        //    DataStructure.erase(it);
            //2 Determine if Key is inbetween pit.
            if (x >= -1000 ||x<=1000 )
            {
                
                //Delete this leprachaun AND put goldVector(of that leprachaun) to 0, and place gold into score.
                DataStructure.erase(it);
                score += LeprachaunGold[vectorIterator];
                LeprachaunGold[vectorIterator] = 0;
                
            }
            //3 Determine if multiple keys(multiple leprachauns in one spot)
            //Count X.
            if (DataStructure.count(x) >= 1)
            {
                //If there are greater than one, two leprachauns are occupying the same spot(same key)
                std::multimap<int, int>::iterator toBeDeleted = DataStructure.find(x);
                
                
                /*range = DataStructure.equal_range(x);
                 for (it = range.first; it != range.second; ++it)
                 {
                 
                 }*/
            }
            
            //4 Leprechaun steals half gold from neighbor(s)
            
            //Move to next leprachaun in Goldvector:
            vectorIterator++;
        }
        t++;
        // code to measure run time
        auto end_time = std::chrono::high_resolution_clock::now();
        auto timeSinceStart = end_time - start_time0;
        timeSinceStartMS = chrono::duration_cast<chrono::milliseconds>(timeSinceStart).count();
    } while (timeSinceStartMS < playtime);
    
    cout << "Number of iterations = " << t << endl;
    cout << "Number of trapped leprechauns = " << nTrapped << endl;
    cout << "Score = " << (long)score << endl;
    return 0;
}