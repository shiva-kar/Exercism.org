class Badge {
    public String print(Integer id, String name, String department) {
        String deptZone = (department == null) ? "OWNER" : department.toUpperCase();
        if (id != null) {
            return String.format("[%d] - %s - %s", id, name, deptZone);
        } 
        return String.format("%s - %s", name, deptZone);
    }
}
