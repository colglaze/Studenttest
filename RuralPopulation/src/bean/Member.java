package bean;

import java.util.Objects;

/*
@author ColGlaze
@create 2024-11-29 -21:01
*/
public class Member {
    private Long id;
    private String name;
    private String identId;
    private String gender;
    private String address;
    private String phoneNum;
    private String  workUnit;
    private Long masterId;

    public Member(Long id, String name, String identId, String gender, String address,
                  String phoneNum, String workUnit, Long masterId) {
        this.id = id;
        this.name = name;
        this.identId = identId;
        this.gender = gender;
        this.address = address;
        this.phoneNum = phoneNum;
        this.workUnit = workUnit;
        this.masterId = masterId;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;

        Member member = (Member) o;

        if (!Objects.equals(id, member.id)) return false;
        if (!Objects.equals(name, member.name)) return false;
        if (!Objects.equals(identId, member.identId)) return false;
        if (!Objects.equals(gender, member.gender)) return false;
        if (!Objects.equals(address, member.address)) return false;
        if (!Objects.equals(phoneNum, member.phoneNum)) return false;
        if (!Objects.equals(workUnit, member.workUnit)) return false;
        return Objects.equals(masterId, member.masterId);
    }

    @Override
    public int hashCode() {
        int result = id != null ? id.hashCode() : 0;
        result = 31 * result + (name != null ? name.hashCode() : 0);
        result = 31 * result + (identId != null ? identId.hashCode() : 0);
        result = 31 * result + (gender != null ? gender.hashCode() : 0);
        result = 31 * result + (address != null ? address.hashCode() : 0);
        result = 31 * result + (phoneNum != null ? phoneNum.hashCode() : 0);
        result = 31 * result + (workUnit != null ? workUnit.hashCode() : 0);
        result = 31 * result + (masterId != null ? masterId.hashCode() : 0);
        return result;
    }

    @Override
    public String toString() {
        return "Member{" +
                "id=" + id +
                ", name='" + name + '\'' +
                ", identId='" + identId + '\'' +
                ", gender='" + gender + '\'' +
                ", address='" + address + '\'' +
                ", phoneNum='" + phoneNum + '\'' +
                ", workUnit='" + workUnit + '\'' +
                ", masterId=" + masterId +
                '}';
    }

    public Long getMasterId() {
        return masterId;
    }

    public void setMasterId(Long masterId) {
        this.masterId = masterId;
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

    public String getWorkUnit() {
        return workUnit;
    }

    public void setWorkUnit(String workUnit) {
        this.workUnit = workUnit;
    }

    public Member() {
    }
}
