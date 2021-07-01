// https://leetcode.com/problems/design-parking-system

    class ParkingSystem {
        HashMap<Integer, Integer> space;

        public ParkingSystem(int big, int medium, int small) {
            space = new HashMap<>();
            space.put(1, big);
            space.put(2, medium);
            space.put(3, small);
        }
        

        public boolean addCar(int carType) {
            if (space.getOrDefault(carType, 0) < 1) return false;
            space.merge(carType, -1, Integer::sum);
            return true;
        }
    }

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem obj = new ParkingSystem(big, medium, small);
 * boolean param_1 = obj.addCar(carType);
 */