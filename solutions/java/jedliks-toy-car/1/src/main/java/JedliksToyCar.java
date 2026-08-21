public class JedliksToyCar {
    int distanceDriven = 0;
    int batteryPercent = 100;
    
    public static JedliksToyCar buy() {
        return new JedliksToyCar();
    }

    public String distanceDisplay() {
        return "Driven " + distanceDriven + " meters";
    }

    public String batteryDisplay() {
        return (batteryPercent > 0) ? "Battery at " + batteryPercent + "%" : "Battery empty";
    }

    public void drive() {
        if (batteryPercent > 0){
            distanceDriven += 20;
            batteryPercent--;
        }
    }
}
