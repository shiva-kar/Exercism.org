class Darts {
    int score(double xOfDart, double yOfDart) {
        double outerRadius = 10.0;
        double middleRadius = 5.0;
        double innerRadius = 1.0;

        double point = (xOfDart * xOfDart) + (yOfDart * yOfDart);
        if (point <= (innerRadius * innerRadius)){
            return 10;
        } else if (point <= (middleRadius * middleRadius)) {
            return 5;
        } else if (point <= (outerRadius * outerRadius)){
            return 1;
        } else {
            return 0;
        }
    }
}
