package bean;

import java.util.Objects;

/*
@author ColGlaze
@create 2024-11-29 -21:02
*/
public class Operator {
    private Long id;
    private String name;
    private String identId;
    private String gender;
    private String address;
    private String phoneNum;
    private String workeAddress;

    public Operator(Long id, String name, String identId, String gender, String address,
                    String phoneNum, String workeAddress) {
        this.id = id;
        this.name = name;
        this.identId = identId;
        this.gender = gender;
        this.address = address;
        this.phoneNum = phoneNum;
        this.workeAddress = workeAddress;
    }

    @Override
    public String toString() {
        return "Operator{" +
                "id=" + id +
                ", name='" + name + '\'' +
                ", identId='" + identId + '\'' +
                ", gender='" + gender + '\'' +
                ", address='" + address + '\'' +
                ", phoneNum='" + phoneNum + '\'' +
                ", workeAddress='" + workeAddress + '\'' +
                '}';
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;

        Operator operator = (Operator) o;

        if (!Objects.equals(id, operator.id)) return false;
        if (!Objects.equals(name, operator.name)) return false;
        if (!Objects.equals(identId, operator.identId)) return false;
        if (!Objects.equals(gender, operator.gender)) return false;
        if (!Objects.equals(address, operator.address)) return false;
        if (!Objects.equals(phoneNum, operator.phoneNum)) return false;
        return Objects.equals(workeAddress, operator.workeAddress);
    }

    @Override
    public int hashCode() {
        int result = id != null ? id.hashCode() : 0;
        result = 31 * result + (name != null ? name.hashCode() : 0);
        result = 31 * result + (identId != null ? identId.hashCode() : 0);
        result = 31 * result + (gender != null ? gender.hashCode() : 0);
        result = 31 * result + (address != null ? address.hashCode() : 0);
        result = 31 * result + (phoneNum != null ? phoneNum.hashCode() : 0);
        result = 31 * result + (workeAddress != null ? workeAddress.hashCode() : 0);
        return result;
    }

    public Long getId() {
        return id;
    }

    public void setId(Long id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getIdentId() {
        return identId;
    }

    public void setIdentId(String identId) {
        this.identId = identId;
    }

    public String getGender() {
        return gender;
    }

    public void setGender(String gender) {
        this.gender = gender;
    }

    public String getAddress() {
        return address;
    }

    public void setAddress(String address) {
        this.address = address;
    }

    public String getPhoneNum() {
        return phoneNum;
    }

    public void setPhoneNum(String phoneNum) {
        this.phoneNum = phoneNum;
    }

    public String getWorkeAddress() {
        return workeAddress;
    }

    public void setWorkeAddress(String workeAddress) {
        this.workeAddress = workeAddress;
    }

    public Operator() {
    }
}
