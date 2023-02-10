#include "Channel.hpp"
#include "User.hpp"

Channel::Channel(std::string name, int modes) : _name(name), _topic("No topic is set"), _modes(modes) {}

Channel::~Channel() {}

const std::string	&Channel::getName() const
{
	return (_name);
}

const std::string	&Channel::getChannelKey() const
{
	return (_channel_key);
}

void	Channel::setChannelKey(const std::string &key)
{
	_channel_key = key;
}

const std::string	&Channel::getTopic() const
{
	return (_topic);
}

void	Channel::setTopic(const std::string &topic)
{
	_topic = topic;
}

size_t	Channel::countUsers() const
{
	return (_users.size());
}

void	Channel::setPrivilege(const User &user, privilege priv)
{
	std::map<const User *, privilege>::iterator	it = _users.find(&user);

	if (it == _users.end())
		return ;
	it->second = priv;
}

int	Channel::findUser(const User &user) const
{
	std::map<const User *, privilege>::const_iterator	it = _users.find(&user);

	if (it == _users.end())
		return (-1);
	return (it->second);
}

void	Channel::removeUser(const User &user)
{
	_users.erase(&user);
}

void	Channel::addUser(User &user, privilege priv)
{
	if (_users.find(&user) == _users.end())
		_users.insert(std::pair<const User *, privilege>(&user, priv));
}


bool	Channel::checkModes(int modes) const
{
	return modes == (_modes & modes);
}

void	Channel::setModes(int modes) 
{
	_modes |= modes;
}

void	Channel::removeModes(int modes) 
{
	_modes &= ~modes;
}

const std::map<const User *, privilege>& Channel::getUsersMap() const {
	return _users;
}
