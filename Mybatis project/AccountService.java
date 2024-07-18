package org.example.service;

import org.example.domain.Account;

import java.util.List;

public interface AccountService {
    void save(Account account);

    void delete(Integer id);

    void update(Account account);

    List<Account> findALL();

    Account findById(Integer id);
}
