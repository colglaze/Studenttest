package bean;

import java.util.Objects;

/*
@author ColGlaze
@create 2024-11-29 -21:01
*/
public class Master {
    private Long id;
    private String name;
    private String identId;
    private String gender;
    private String address;
    private String phoneNum;
    private Long houseArea;
    private Long peopleSize;
    private Long poorId;
    private String poorName;

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

    public Master(Long id, String name, String identId, String gender, String address,
                  String phoneNum, Long houseArea, Long peopleSize, Long poorId, String poorName) {
        this.id = id;
        this.name = name;
        this.identId = identId;
        this.phoneNum = phoneNum;
        this.houseArea = houseArea;
        this.peopleSize = peopleSize;
        this.poorId = poorId;
        this.gender = gender;
        this.address = address;
        this.poorName = poorName;
    }
    public Master(Long id, String name, String identId, String gender, String address,
                  String phoneNum, Long houseArea, Long peopleSize, Long poorId) {
        this.id = id;
        this.name = name;
        this.identId = identId;
        this.phoneNum = phoneNum;
        this.houseArea = houseArea;
        this.peopleSize = peopleSize;
        this.poorId = poorId;
        this.gender = gender;
        this.address = address;
    }

    public Master() {
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

    public String getPhoneNum() {
        return phoneNum;
    }

    public void setPhoneNum(String phoneNum) {
        this.phoneNum = phoneNum;
    }

    public Long getHouseArea() {
        return houseArea;
    }

    public void setHouseArea(Long houseArea) {
        this.houseArea = houseArea;
    }

    public Long getPeopleSize() {
        return peopleSize;
    }

    public void setPeopleSize(Long peopleSize) {
        this.peopleSize = peopleSize;
    }

    public Long getPoorId() {
        return poorId;
    }

    public void setPoorId(Long poorId) {
        this.poorId = poorId;
    }

    @Override
    public String toString() {
        return "Master{" +
                "id=" + id +
                ", name='" + name + '\'' +
                ", identId='" + identId + '\'' +
                ", gender='" + gender + '\'' +
                ", address='" + address + '\'' +
                ", phoneNum='" + phoneNum + '\'' +
                ", houseArea=" + houseArea +
                ", peopleSize=" + peopleSize +
                ", poorId=" + poorId +
                ", poorName='" + poorName + '\'' +
                '}';
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;

        Master master = (Master) o;

        if (!Objects.equals(id, master.id)) return false;
        if (!Objects.equals(name, master.name)) return false;
        if (!Objects.equals(identId, master.identId)) return false;
        if (!Objects.equals(gender, master.gender)) return false;
        if (!Objects.equals(address, master.address)) return false;
        if (!Objects.equals(phoneNum, master.phoneNum)) return false;
        if (!Objects.equals(houseArea, master.houseArea)) return false;
        if (!Objects.equals(peopleSize, master.peopleSize)) return false;
        if (!Objects.equals(poorId, master.poorId)) return false;
        return Objects.equals(poorName, master.poorName);
    }

    @Override
    public int hashCode() {
        int result = id != null ? id.hashCode() : 0;
        result = 31 * result + (name != null ? name.hashCode() : 0);
        result = 31 * result + (identId != null ? identId.hashCode() : 0);
        result = 31 * result + (gender != null ? gender.hashCode() : 0);
        result = 31 * result + (address != null ? address.hashCode() : 0);
        result = 31 * result + (phoneNum != null ? phoneNum.hashCode() : 0);
        result = 31 * result + (houseArea != null ? houseArea.hashCode() : 0);
        result = 31 * result + (peopleSize != null ? peopleSize.hashCode() : 0);
        result = 31 * result + (poorId != null ? poorId.hashCode() : 0);
        result = 31 * result + (poorName != null ? poorName.hashCode() : 0);
        return result;
    }

    public String getPoorName() {
        return poorName;
    }

    public void setPoorName(String poorName) {
        this.poorName = poorName;
    }
}
