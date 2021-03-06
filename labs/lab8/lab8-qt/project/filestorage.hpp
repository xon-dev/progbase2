#ifndef FILESTORAGE_H
#define FILESTORAGE_H

#include "storage.hpp"

#include <fstream>

using namespace std;

class FileStorage: public Storage {
protected:
  fstream orgs_file_;
  fstream fndrs_file_;

  // orgs
  virtual vector<Organisation> loadOrgs() = 0;
  virtual void saveOrgs(const vector<Organisation>&) = 0;
  virtual int getNewOrgId() = 0;

  // fndrs
  virtual vector<Founder> loadFndrs() = 0;
  virtual void saveFndrs(const vector<Founder>&) = 0;
  virtual int getNewFndrId() = 0;

public:
  FileStorage(const string& dir_name): Storage(dir_name) {}

  bool isOpen() const;
  bool open(string);
  void close();

  // orgs
  vector<Organisation> getAllOrgs(void);
  optional<Organisation> getOrgById(int org_id);
  bool updateOrg(const Organisation& org);
  bool removeOrg(int org_id);
  int insertOrg(const Organisation& org);

  // fndrs
  vector<Founder> getAllFndrs(void);
  optional<Founder> getFndrById(int fndr_id);
  bool updateFndr(const Founder& fndr);
  bool removeFndr(int fndr_id);
  int insertFndr(const Founder& fndr);
};

#endif    // FILESTORAGE_H
