class Badge {
    public String print(Integer id, String name, String department) {
        String deptZone = (department == null) ? "OWNER" : department.toUpperCase();
        if (id != null) {
            return "[" + id + "]" + " - " + name + " - " + deptZone;
        } 
        return name + " - " + deptZone;
    }
}
