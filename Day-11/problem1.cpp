int findContentChildren(vector<int>& g, vector<int>& s) {
    // Sorting the arrays in ascending order
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    // Initializing variables for child and cookie indices
    int childIndex = 0, cookieIndex = 0;

    // Iterate through the arrays while there are still children and cookies
    while (childIndex < g.size() && cookieIndex < s.size()) {
        // If the current cookie is sufficient for the current child
        if (s[cookieIndex] >= g[childIndex])
            childIndex++; // Move to the next child

        cookieIndex++; // Move to the next cookie
    }

    // Return the count of children who got cookies
    return childIndex;
}
