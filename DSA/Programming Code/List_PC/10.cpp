List<E>* merge(List<E>* in1, List<E>* in2) {
     List<E> *res = new LList<E>(in1->length() + in2->length());
        in1->moveToStart(), in2->moveToStart();
        while (in1->currPos() < in1->length() && in2->currPos() < in2->length()) {
            if (in1->getValue() <= in2->getValue()) {
                res->insert(in1->getValue());
                res->next();
                in1->next();
            }
            else {
                res->insert(in2->getValue());
                res->next();
                in2->next();
            }
        }
        while (in1->currPos() < in1->length()) {
            res->insert(in1->getValue());
            res->next();
            in1->next();
        }
        while (in2->currPos() < in2->length()) {
            res->insert(in2->getValue());
            res->next();
            in2->next();
        }
        res->moveToStart();
        return res;
}