bool comparePoints(const Point& a, const Point& b, const Point& des_point) {
    double distA = sqrt(pow(a.x - des_point.x, 2) + pow(a.y - des_point.y, 2));
    double distB = sqrt(pow(b.x - des_point.x, 2) + pow(b.y - des_point.y, 2));
    return distA < distB;
}

void closestKPoints(Point points[], int n, Point& des_point, int k) {
    vector<Point> pointVector(points, points + n);
    sort(pointVector.begin(), pointVector.end(), [&](const Point& a, const Point& b) {
        return comparePoints(a, b, des_point);
    });

    for (int i = 0; i < min(k, n); ++i) {
        pointVector[i].display();
        cout << endl;
    }
}