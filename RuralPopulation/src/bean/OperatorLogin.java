package bean;

import java.util.Objects;

/*
@author ColGlaze
@create 2024-11-30 -15:40
*/
public class OperatorLogin {
    private Long id;
    private String username;
    private String password;

    @Override
    public String toString() {
        return "OperatorLogin{" +
                "id=" + id +
                ", username='" + username + '\'' +
                ", password='" + password + '\'' +
                '}';
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;

        OperatorLogin that = (OperatorLogin) o;

        if (!Objects.equals(id, that.id)) return false;
        if (!Objects.equals(username, that.username)) return false;
        return Objects.equals(password, that.password);
    }

    @Override
    public int hashCode() {
        int result = id != null ? id.hashCode() : 0;
        result = 31 * result + (username != null ? username.hashCode() : 0);
        result = 31 * result + (password != null ? password.hashCode() : 0);
        return result;
    }

    public Long getId() {
        return id;
    }

    public void setId(Long id) {
        this.id = id;
    }

    public String getUsername() {
        return username;
    }

    public void setUsername(String username) {
        this.username = username;
    }

    public String getPassword() {
        return password;
    }

    public void setPassword(String password) {
        this.password = password;
    }

    public OperatorLogin(Long id, String username, String password) {
        this.id = id;
        this.username = username;
        this.password = password;
    }

    public OperatorLogin() {
    }
}
