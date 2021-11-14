typedef long long ll;

class Solution {
    struct Car{
        ll pos;
        ll speed;
        bool operator<(const Car& rhs) const {
            return pos < rhs.pos;
        }
    };
    bool slowerOrEqual(Car& car1, Car& car2, int target) {
        return (target - car1.pos) * car2.speed <= (target - car2.pos) * car1.speed;
    }
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<Car> cars;
        int N = position.size();
        for(int i = 0; i < N; ++i) {
            cars.push_back(Car{position[i], speed[i]});
        }
        sort(begin(cars), end(cars));
        
        int ans = N;
        Car slowestCar = cars.back();
        for(int i = N-2; i >= 0; --i) {
            if(slowerOrEqual(cars[i], slowestCar, target)) {
                --ans;
            } else {
                slowestCar = cars[i];
            }
        }
        return ans;
    }
};