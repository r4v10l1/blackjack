
// =============================================================================
// HELPERS
// =============================================================================

char* n2str(int number) {
    switch (number) {
        case 1:     return TC_B_WHT "A"  TC_NRM;    break;
        case 2:     return TC_B_WHT "2"  TC_NRM;    break;
        case 3:     return TC_B_WHT "3"  TC_NRM;    break;
        case 4:     return TC_B_WHT "4"  TC_NRM;    break;
        case 5:     return TC_B_WHT "5"  TC_NRM;    break;
        case 6:     return TC_B_WHT "6"  TC_NRM;    break;
        case 7:     return TC_B_WHT "7"  TC_NRM;    break;
        case 8:     return TC_B_WHT "8"  TC_NRM;    break;
        case 9:     return TC_B_WHT "9"  TC_NRM;    break;
        case 10:    return TC_B_WHT "10" TC_NRM;    break;
        case 11:    return TC_B_WHT "J"  TC_NRM;    break;
        case 12:    return TC_B_WHT "Q"  TC_NRM;    break;
        case 13:    return TC_B_WHT "K"  TC_NRM;    break;
        default:    break;
    }

    return "";
}

char* s2str(int suit) {
    switch (suit) {
        case DIAMONDS:      return TC_B_RED "\x4" TC_NRM;     break;
        case CLUBS:         return TC_B_NRM "\x5" TC_NRM;     break;
        case HEARTS:        return TC_B_RED "\x3" TC_NRM;     break;
        case SPADES:        return TC_B_NRM "\x6" TC_NRM;     break;
        default:            break;
    }

    return "";
}

void separator() {
    printf(TC_B_WHT "======================================================================================\n\n" TC_NRM);
}