#ifndef RULES_H
#define RULES_H

#define IP "192.168.2.233"
#define PORT 8888

const std::string split_type_gid = ":";
const std::string split_gid_id = "!";
const std::string split_id_msg = "|";
const std::string msg_end = "__MSGED__\0";
const std::string split_type_id = "#";
const std::string split_id_pwd = "$";
const std::string split_id_name = "-";
const std::string split_client_client = ";";
const std::string split_key_change = "+";
const std::string split_yourname_friendlist = "&";
const std::string splitidname = "..";

enum Signal{LogIn,SignUp,BadCLient,Normal,SomeError,UsrInfo,
    ConnectSuccess,LogInSuccess, WrongPassword,//登陆消息
    FriendRequest,NormalMessage,GroupMessage,GroupCreate,GroupCreateSuccess,
    RequestAgree,RequestRefuse,ChangeSet,GetInfo,//用户消息类型
    //系统消息类型
    ChangeSetFailure,ChangeSetSuccess,GetInfoSuccess,GetInfoFailure,
};

#endif // RULES_H
