char* addBinary(char* a, char* b) {

    int i = strlen(a) - 1;
    int j = strlen(b) - 1;

    int carry = 0;

    char* ans = (char*)malloc(10005);

    int k = 0;

    while(i >= 0 || j >= 0 || carry) {

        int sum = carry;

        if(i >= 0) {
            sum += a[i] - '0';
            i--;
        }

        if(j >= 0) {
            sum += b[j] - '0';
            j--;
        }

        ans[k++] = (sum % 2) + '0';

        carry = sum / 2;
    }

    ans[k] = '\0';

    for(int l = 0, r = k - 1; l < r; l++, r--) {

        char temp = ans[l];
        ans[l] = ans[r];
        ans[r] = temp;
    }

    return ans;
}
