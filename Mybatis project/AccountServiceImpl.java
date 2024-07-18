package org.example.service.Impl;

import org.example.dao.AccountDao;
import org.example.domain.Account;
import org.example.service.AccountService;
import org.springframework.beans.factory.annotation.Autowired;
import java.util.List;

@Service
public class AccountServiceImpl implements AccountService {
    @Autowired
    private AccountDao accountDao;


    @Override
    public void save(Account account) { accountDao.save(account);}

    @Override
    public void delete(Integer id) { accountDao.delet(id);}

    @Override
    public void update(Account account) { accountDao.update(account); }

    @Override
    public List<Account> findALL() { return accountDao.findAll();}

    @Override
    public Account findById(Integer id) { return accountDao.findById(id); }
}
