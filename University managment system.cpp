using System;
using System.Collections.Generic;
using System.IO;

public abstract class Person
{
    public string Name { get; set; } = " ";
    public int Age { get; set; }
    public int Id { get; set; }

    public Person() { }

    public Person(string name, int age, int id)
    {
        Name = name;
        Age = age;
        Id = id;
    }

    public abstract void Role();
}

public class Manager : Person
{
    private static Manager _instance;
    private int _salary;

    private Manager() { }

    public static Manager GetInstance()
    {
        if (_instance == null)
        {
            _instance = new Manager();
        }
        return _instance;
    }

    public void SetSalary(int salary)
    {
        _salary = salary;
    }

    public int GetSalary()
    {
        return _salary;
    }

    public override void Role()
    {
        Console.WriteLine("Manager role");
    }
}

public class Student : Person
{
    public float GPA { get; set; }

    public Student(string name, int age, int id, float gpa) : base(name, age, id)
    {
        GPA = gpa;
    }

    public override void Role()
    {
        Console.WriteLine("Student role");
    }
}

public class Instructor : Person
{
    public int Salary { get; set; }
    public int Hours { get; set; }

    public Instructor(string name, int age, int id, int salary, int hours) : base(name, age, id)
    {
        Salary = salary;
        Hours = hours;
    }

    public override void Role()
    {
        Console.WriteLine("Instructor role");
    }
}

public class Employee : Person
{
    public int Salary { get; set; }

    public Employee(string name, int age, int id, int salary) : base(name, age, id)
    {
        Salary = salary;
    }

    public override void Role()
    {
        Console.WriteLine("Employee role");
    }
}

public class Course
{
    public string Title { get; set; } = " ";
    public int CourseId { get; set; }

    public void Details()
    {
        Console.WriteLine($"{Title}\n{CourseId}");
    }
}

public class Department
{
    public string Title { get; set; }
    public List<Course> Courses { get; set; }

    public Department(string title, List<Course> courses)
    {
        Title = title;
        Courses = courses;
    }

    public void AddCourses(Course course)
    {
        string coursesFile = "Courses.txt";
        using (StreamWriter writer = new StreamWriter(coursesFile, append: true))
        {
            foreach (var c in Courses)
            {
                writer.WriteLine(c.Title);
                writer.WriteLine(c.CourseId);
            }
        }
        Console.WriteLine("Data written to file successfully.");
    }
}

public class Faculty
{
    public string Title { get; set; }
    public List<Student> Students { get; set; }
    public List<Instructor> Instructors { get; set; }
    public List<Employee> Employees { get; set; }
    public List<Department>
