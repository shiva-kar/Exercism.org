public class CarsAssemble {
    static final int BASE_PRODUCTION_RATE = 221;
    public double productionRatePerHour(int speed) {
        if (speed > 0 && speed <= 4) return BASE_PRODUCTION_RATE * speed * 1.0;
        else if (speed > 4 && speed <= 8) return BASE_PRODUCTION_RATE * speed * 0.9;
        else if (speed == 9) return BASE_PRODUCTION_RATE * speed * 0.8;
        else if (speed == 10) return BASE_PRODUCTION_RATE * speed * 0.77;
        else return 0.0;
    }

    public int workingItemsPerMinute(int speed) {
        return (int)productionRatePerHour(speed) / 60;
    }
}
