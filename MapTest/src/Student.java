import java.util.Objects;

/*
@author ColGlaze
@create 2024-08-01 -20:46
*/
public class Student implements Comparable {
    private String name;
    private int age;

    public Student(String name, int age) {
        this.name = name;
        this.age = age;
    }

    public Student() {
    }

    @Override
    public String toString() {
        return "Student{" +
                "name='" + name + '\'' +
                ", age=" + age +
                '}';
    }

    public String getName() {
        return name;
    }

    public int getAge() {
        return age;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Student student = (Student) o;
        return age == student.age && Objects.equals(name, student.name);
    }

    @Override
    public int hashCode() {
        return Objects.hash(name, age);
    }

    @Override
    public int compareTo(Object o) {
        if(o instanceof Student)
        {
            Student s = (Student) o;
            if(this.age > s.getAge())
            {
                return 1;
            }
            else if(this.age < s.getAge())
            {
                return -1;
            }
            else {
                return 0;
            }
        }
        throw new RuntimeException("类型不符");
    }
}
