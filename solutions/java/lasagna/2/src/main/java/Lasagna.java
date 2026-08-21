public class Lasagna {
    private int expectedOvenTime = 40;
    
    public int expectedMinutesInOven(){
        return expectedOvenTime;
    }

    public int remainingMinutesInOven(int timePassed){
        return expectedMinutesInOven() - timePassed;
    }
    
    public int preparationTimeInMinutes(int layersNumber){
        return layersNumber * 2;
    }
    
    public int totalTimeInMinutes(int layersNumber, int timePassed){
        return timePassed + preparationTimeInMinutes(layersNumber);
    }
}
