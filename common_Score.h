#ifndef COMMON_SCORE_H_
#define COMMON_SCORE_H_

#include <mutex>
#include <condition_variable>

class Score {
public:
	Score(std::mutex &m);

	~Score();

	void addWinner();

	void addLoser();

	void show();

private:
	int winers;
	int losers;
	std::mutex &m;
	std::condition_variable cv;
};

#endif /* COMMON_SCORE_H_ */
