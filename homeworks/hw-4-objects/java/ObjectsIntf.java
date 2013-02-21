public interface ObjectsIntf {

    /** 
     * Create and return a student object whose name, age, and major
     * are the same as those given as input here.  - 1 point
     **/
    Student makeStudent(String name, int age, String major);

    /** 
     * Add one to the given student's age. This function doesn't
     * return anything! So all you need to do is increment the
     * student's age, and if student looks one year older after this
     * function completes, you did your job.  - 2 points
     **/
    void makeStudentOlder(Student student);

    /**
     * create and return a new Student object that has the same name,
     * age, and major as the input student.  - 2 points
     **/
    Student copyStudent(Student student);

    /**
     * Most college students are younger than 23. We'd like to know if
     * this student is older than 23. Return True if that is the case.
     * - 1 point
     **/
    boolean isOlder(Student student);

    /**
     * Musicians are a lot of fun, so let's find out if the student's
     * major is 'Music' or not. Return True if the major is 'Music'.
     * - 1 point
     **/
    boolean isMusician(Student student);

    /**
     * A little known fact: musicians older than 23 have substantially
     * more fun than other people. Return True only if the given
     * student is both a musician and is older than 23.  - 3 points
    **/
    boolean isOlderMusician(Student student);

}
