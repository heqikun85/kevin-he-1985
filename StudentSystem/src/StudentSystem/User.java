package StudentSystem;

public class User {
    private String userName;
    private String passWord;
    private String personId;
    private String phoneNum;

    public User(){
        
    }

    public User(String userName, String passWord, String personId, String phoneNum){
        this.userName = userName;
        this.passWord = passWord;
        this.personId = personId;
        this.phoneNum = phoneNum;
    }

    public String getName(){
        return userName;
    }

    public void setName(String userName){
        this.userName = userName;
    }

    public String getPass(){
        return passWord;
    }

    public void setPass(String passWord){
        this.passWord = passWord;
    }

    public String getPerson(){
        return personId;
    }

    public void setPerson(String personId){
        this.personId = personId;
    }

    public String getPhone(){
        return phoneNum;
    }

    public void setPhone(String phoneNum){
        this.phoneNum = phoneNum;
    }
}
