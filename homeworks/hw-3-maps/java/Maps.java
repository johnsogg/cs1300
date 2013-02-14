/*
 * Maps.java
 *
 * Please see the documentation in MapsIntf.java for wisdom on what
 * these methods below are supposed to do.
 */

import java.util.Map;
import java.util.HashMap; // you might needs this
import java.util.List;
import java.util.ArrayList; // you might needs this

public class Maps implements MapsIntf {

    public Map makeEmptyDictionary() {
	return null; // implement me
    }

    public Map makeStudentDictionary() {
	return null; // implement me
    }

    public Map makeRealStudentDictionary(String name, int age, String major) {
	return null; // implement me
    }

    public List getStudentDictionaryAsList(Map student) {
	return null; // implement me
    }

    public Map whichStudentIsOlder(Map studentA, Map studentB) {
	return null; // implement me
    }

    public boolean areStudentsTheSame(Map studentA, Map studentB) {
	return false; // implement me
    }
}
