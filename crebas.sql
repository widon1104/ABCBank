/*==============================================================*/
/* DBMS name:      MySQL 5.0                                    */
/* Created on:     2013/8/5 15:56:57                            */
/*==============================================================*/


drop table if exists ABSTRACT;

drop table if exists BANK_ACCOUNT;

drop table if exists TELLER;

drop table if exists TRANS;

/*==============================================================*/
/* Table: ABSTRACT                                              */
/*==============================================================*/
create table ABSTRACT
(
   ABSTRACT_ID          int not null auto_increment,
   NAME                 varchar(16),
   primary key (ABSTRACT_ID)
);

/*==============================================================*/
/* Table: BANK_ACCOUNT                                          */
/*==============================================================*/
create table BANK_ACCOUNT
(
   ACCOUNT_ID           int not null auto_increment,
   NAME                 varchar(16),
   PASS                 varchar(16),
   ID                   char(18),
   BALANCE              decimal(10,2),
   OPEN_DATE            datetime,
   FLAG                 tinyint,
   primary key (ACCOUNT_ID)
);

/*==============================================================*/
/* Table: TELLER                                                */
/*==============================================================*/
create table TELLER
(
   TELLER_ID            int not null auto_increment,
   TELLER_NAME          varchar(16),
   TELLER_PASS          varchar(16),
   primary key (TELLER_ID)
);

/*==============================================================*/
/* Table: TRANS                                                 */
/*==============================================================*/
create table TRANS
(
   TRANS_ID             int not null auto_increment,
   ACCOUNT_ID           int,
   OTHER_ACCOUNT_ID     int,
   ABSTRACT_ID          int,
   MONEY                decimal(10,2),
   BALANCE              decimal(10,2),
   TRANS_DATE           datetime,
   primary key (TRANS_ID)
);

alter table TRANS add constraint FK_ACCOUNT_ID foreign key (ACCOUNT_ID)
      references BANK_ACCOUNT (ACCOUNT_ID) on delete restrict on update restrict;

alter table TRANS add constraint FK_ABSTRACT_ID foreign key (ABSTRACT_ID)
      references ABSTRACT (ABSTRACT_ID) on delete restrict on update restrict;

alter table TRANS add constraint FK_OTHER_ACCOUNT_ID foreign key (OTHER_ACCOUNT_ID)
      references BANK_ACCOUNT (ACCOUNT_ID) on delete restrict on update restrict;

/* set names gbk; */

/*==============================================================*/
/* 初始数据                                                     */
/*==============================================================*/
insert into TELLER values(1, 'admin', '123456');
insert into ABSTRACT values(1, '开户');
insert into ABSTRACT values(2, '存款');
insert into ABSTRACT values(3, '取款');
insert into ABSTRACT values(4, '转入');
insert into ABSTRACT values(5, '转出');
