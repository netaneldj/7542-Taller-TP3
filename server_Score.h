#ifndef SERVER_SCORE_H_
#define SERVER_SCORE_H_

#include <mutex>
#include <condition_variable>

class Score {
public:
	explicit Score(std::mutex &m);

	~Score();

	void addWinner();

	void addLoser();

	void show();

private:
	int winers;
	int losers;
	std::mutex &m;
};

#endif /* SERVER_SCORE_H_ */
