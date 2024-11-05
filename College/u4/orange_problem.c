#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100 // Maximum number of users

//structure for a message in a dll
typedef struct message
{
    char content[300]; //message content
    char sender[50]; //Sender ID
    struct message *next; //pointer to the next message
    struct message *prev; //pointer to the prev message
}Message;

//structure for the chat history(DLL of the messages)
typedef struct Chat
{
    Message *head; //pointer to the first message
    Message *tail; //pointer to the last message
}Chat;

typedef struct User
{
    char userId[50]; //UserId
    char username[50]; //Username
    Chat chathist; //Chathistory(one-one or group chat)
}User;

//Hashmap for storing the user
User *userdirectory[MAX_USERS];

int hashfunction(char *userId)
{
    int hash=0;
    for(int i=0;i<userId[i]!='\0';i++)
    {
        hash=(hash+userId[i])%MAX_USERS; //hash function
    }
    return hash;    
}

User *finduser(char *user)
{
    int index = hashfunction(user);
    return userdirectory[index];
}

// Function to create a new user
void createUser(char *userId, char *username) 
{
    int index=hashfunction(userId); //index is the hashcode
    User *newuser=(User*)malloc(sizeof(User));
    strcpy(newuser->userId,userId);
    strcpy(newuser->username,username);
    newuser->chathist.head=NULL;
    newuser->chathist.tail=NULL;
    userdirectory[index]=newuser;
}

Message *createMessage(char *message,char *senderid)
{
    Message *newmessage=(Message*)malloc(sizeof(Message));
    strcpy(newmessage->content,message);
    strcpy(newmessage->sender,senderid);
    newmessage->next = newmessage->prev = NULL;
    return newmessage;
}

//function to send messages to new messages(add to the chat history)
void sendMessage(User *sender,char *message,char *senderid)
{
    Message *newm = createMessage(message,senderid);
    if(sender->chathist.tail == NULL) //initially there are no messages
    {
        sender->chathist.head = sender->chathist.tail = newm;
    }
    else
    {
        //add the new message at the end of the list
        sender->chathist.tail->next=newm;
        newm->prev = sender->chathist.tail;
        sender->chathist.tail = newm;
    }
}

void listmessage(User *user)
{
    Message *current= user->chathist.head;
    if(current == NULL)
    {
        printf("No messages in the chat\n");
        return;
    }
    while(current!=NULL)
    {
        printf("%s : %s\n",current->sender,current->content);
        current = current->next;
    }
}



int main()
{
    //initialize the user directory
    for(int i=0;i<MAX_USERS;i++)
    {
        userdirectory[i]=NULL;
    }

    int num_users,num_messages;
    char user_id[50],username[50],senderid[50],message[100];
    printf("Enter number of users to create:");
    scanf("%d",&num_users);
    for(int i=0;i<num_users;i++)
    {
        printf("\nEnter the USERID");
        scanf("%s",user_id);
        printf("\nEnter the Username");
        scanf("%s",username);

        createUser(user_id,username); //function call
    }

    //input for sending the messages
    printf("\nEnter the number of messages to send:");
    scanf("%d",&num_messages);
    for(int i=0;i<num_messages;i++)
    {
        printf("Enter the Sender Id:");
        scanf("%s",senderid);
        printf("\nEnter the message content:");
        getchar(); //consume the leftover newline from the previous input
        fgets(message,sizeof(message),stdin);

        User *sender= finduser(senderid); //function call
        if(sender==NULL)
        {
            printf("user not found");
            continue;
        }
        sendMessage(sender,message,senderid);
    }

    printf("\nEnter the userid to display the chat history:");
    scanf("%s",user_id);
    User *user = finduser(user_id);
    listmessage(user);
}


