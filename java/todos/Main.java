import javax.swing.*;

class todo{
    String work;

    public todo(String work, String start, String end) {
        this.work = work;
        this.start = start;
        this.end = end;
    }

    public todo() {
    }

    public String getStart() {
        return start;
    }

    public void setStart(String start) {
        this.start = start;
    }

    public String getWork() {
        return work;
    }

    public void setWork(String work) {
        this.work = work;
    }

    public String getEnd() {
        return end;
    }

    public void setEnd(String end) {
        this.end = end;
    }

    String start;
    String end;
}



public class Main {
}
