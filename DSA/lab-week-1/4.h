class Book
{
private:
    char* title;
    char* authors;
    int publishingYear;

public:
    Book()
    {
        /*
         * STUDENT ANSWER
         * TODO: set zero publishingYear and null pointer
         */
         title = NULL;
         authors = NULL;
         publishingYear = 0;
    }

    Book(const char* title, const char* authors, int publishingYear)
    {
        /*
         * STUDENT ANSWER
         */
        this->setTitle(title);
        this->setAuthors(authors);
        this->publishingYear = publishingYear;
    }

    Book(const Book &book)
    {
        /*
         * STUDENT ANSWER
         * TODO: deep copy constructor
         */
        int str_t = strlen(book.title), str_a = strlen(book.authors);
        this->title = new char[str_t + 1];
        for (int i = 0; i < str_t; i++) {
            title[i] = book.title[i];
        }
        title[str_t] = '\0';
        this->authors = new char[str_a + 1];
        for (int i = 0; i < str_a; i++) {
            authors[i] = book.authors[i];
        }
        authors[str_a] = '\0';
        this->publishingYear = book.publishingYear;
    }
    
    void setTitle(const char* title)
    {
        /*
         * STUDENT ANSWER
         */
        int str_t = strlen(title);
        this->title = new char[str_t + 1];
        for (int i = 0; i < str_t; i++) {
            this->title[i] = title[i];
        }
        this->title[str_t] = '\0';
    }

    void setAuthors(const char* authors)
    {
        /*
         * STUDENT ANSWER
         */
        int str_a = strlen(authors);
        this->authors = new char[str_a + 1];
        for (int i = 0; i < str_a; i++) {
            this->authors[i] = authors[i];
        }
        this->authors[str_a] = '\0';
    }

    void setPublishingYear(int publishingYear)
    {
        /*
         * STUDENT ANSWER
         */
         this->publishingYear = publishingYear;
    }

    char* getTitle() const
    {
        /*
         * STUDENT ANSWER
         */
        return title;
    }

    char* getAuthors() const
    {
        /*
         * STUDENT ANSWER
         */
         return authors;
    }

    int getPublishingYear() const
    {
        /*
         * STUDENT ANSWER
         */
         return publishingYear;
    }

    ~Book()
    {
        /*
         * STUDENT ANSWER
         */
        delete[] title;
        delete[] authors;
    }

    void printBook(){
        printf("%s\n%s\n%d", this->title, this->authors, this->publishingYear);
    }
};