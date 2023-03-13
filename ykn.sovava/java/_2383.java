package java;

/**
 * Description: TODO
 *
 * @author: ykn
 * @date: 2023年03月13日 11:31
 **/
public class _2383 {
    public int minNumberOfHours(int initialEnergy, int initialExperience, int[] energy, int[] experience) {
        int hour = 0;
        int n = energy.length;
        int tempExp = initialExperience;
        int tempEne = initialEnergy;
//        hour = -initialEnergy;
        for (int i = 0; i < n; i++) {
            if (tempEne <= energy[i]) {
                hour += energy[i] - tempEne + 1;
                tempEne += energy[i] - tempEne + 1;
            }
            tempEne -= energy[i];

            if (tempExp <= experience[i]) {
                hour += experience[i] - tempExp + 1;
                tempExp += experience[i] - tempExp + 1;
            }
            tempExp+=experience[i];
        }
        return hour;
    }
}
