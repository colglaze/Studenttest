/*
@author ColGlaze
@create 2024-07-30 -20:54
*/
public enum Season {
    SPRING("SPRING","春暖花开"),
    SUMMER("SUMMER","夏日禁果"),
    AUTUMN("AUTUMN","秋日丰收"),
    WINTER("WINTER","冰天雪地");

    private String SeasonName;
    private String SeasonDescr;

    @Override
    public String toString() {
        return "Season{" +
                "SeasonName='" + SeasonName + '\'' +
                ", SeasonDescr='" + SeasonDescr + '\'' +
                '}';
    }

    Season(String seasonName, String seasonDescr) {
        SeasonName = seasonName;
        SeasonDescr = seasonDescr;
    }
}
