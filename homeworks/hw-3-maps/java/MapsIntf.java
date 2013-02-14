
import java.util.Map;
import java.util.List;

public interface MapsIntf {

    /**
     * create an empty dictionary and return it.
     *  1 point
     **/
    public Map makeEmptyDictionary();

    /**
     * create and return a dictionary that contains the following
     * key/value pairs:
     * 'name' should be 'Unknown Name'
     * 'age' should be 'Unknown Age'
     * 'major' should be 'Unknown Major'
     * 1 point
     **/
    public Map makeStudentDictionary();


    /**
     * create and return a dictionary that contains the same keys as
     * listed in the make_student_directory function, but has the
     * values indictated in this function's parameter list. 'name' and
     * 'major' will be strings, and 'age' will be an integer.  
     * 1 point
     **/
    public Map makeRealStudentDictionary(String name, int age, String major);

    /**
     * make and return a list based on a student dictionary. The list
     * should have the following elements:
     *
     * index 0: the student's name
     * index 1: the student's major
     * index 2: the student's age
     *   2 points
     **/
    public List getStudentDictionaryAsList(Map student);

    /**
     * Examine the student dictionaries provided as input parameters,
     * and return whichever has the larger number in the 'age'
     * category. if they are the same age, return student_a.  
     * 2 points
     **/
    public Map whichStudentIsOlder(Map studentA, Map studentB);

    /**
     * Examine the student dictionaries and return True if they have
     * the same name, age, and major. return False otherwise.  
     * 3 points
     **/
    public boolean areStudentsTheSame(Map studentA, Map studentB);

}
