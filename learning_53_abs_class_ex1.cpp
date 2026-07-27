#include <iostream>
#include <memory>
#include<string>
#include<vector>

class ICloudStorage{
    public:
    virtual void uploadFile(std::string filename) = 0;
    virtual void downloadFile(std:: string filename) = 0;
    
};
class S3Storage:public ICloudStorage{
    public:
    void uploadFile(std::string f_name) override{
        std::cout<<"Uploading "<<f_name<<" to AWS S3....Done\n";
    }
    void downloadFile(std::string f_name) override{
        std::cout<<"Downloading "<<f_name<< " from AWS S3.....Done\n";
    }
};
class GoogleDriveStorage:public ICloudStorage{
    public:
    void uploadFile(std::string f_name) override{
        std::cout<<"Uploading "<<f_name<<" to Google Drive....Done\n";
    }
    void downloadFile(std::string f_name) override{
        std::cout<<"Downloading "<<f_name<< " from Google Drive.....Done\n";
    }
};

int main(){
    std::vector<std::unique_ptr<ICloudStorage>> database;
    database.push_back(std::make_unique<S3Storage>());
    database.push_back(std::make_unique<GoogleDriveStorage>());
    for(const auto& database_storage: database){
        database_storage->uploadFile("path/to/the/file.cpp");
        database_storage->downloadFile("path/to/the/file.cpp");
    }
    return 0;
}