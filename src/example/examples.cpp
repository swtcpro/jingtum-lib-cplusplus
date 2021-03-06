
#include "pch.h"
#include <jingtum-lib/jingtumlib.h>
#pragma comment(lib,"../../../lib/jingtumlib/jingtumStaticLib-release.lib") 

void callback_print(std::string, std::string, jingtumlib::Remote *);                     // 3. connect方法回调
void callback_requestServerInfo(std::string, std::string, jingtumlib::Remote *);         // 4. requestServerInfo方法回调
void callback_requestLedgerClosed(std::string, std::string, jingtumlib::Remote *);       // 5. requestLedgerClosed方法回调
void callback_requestLedger(std::string, std::string, jingtumlib::Remote *);             // 6. requestLedger方法回调
void callback_requestTx(std::string, std::string, jingtumlib::Remote *);                 // 7. requestTx方法回调
void callback_requestAccountInfo(std::string, std::string, jingtumlib::Remote *);        // 8. requestAccountInfo方法回调
void callback_requestAccountTums(std::string, std::string, jingtumlib::Remote *);        // 9. requestAccountTums方法回调
void callback_requestAccountRelations(std::string, std::string, jingtumlib::Remote *);   // 10. requestAccountRelations方法回调
void callback_requestAccountOffers(std::string, std::string, jingtumlib::Remote *);      // 11. requestAccountOffers方法回调
void callback_requestAccountTx(std::string, std::string, jingtumlib::Remote *);          // 12. requestAccountTx方法回调
void callback_requestOrderBook(std::string, std::string, jingtumlib::Remote *);          // 13. requestOrderBook方法回调
void callback_buildPaymentTx(std::string, std::string, jingtumlib::Remote *);            // 14. buildPaymentTx方法回调
void callback_buildRelationTx(std::string, std::string, jingtumlib::Remote *);           // 15. buildRelationTx方法回调
void callback_buildAccountSetTx(std::string, std::string, jingtumlib::Remote *);         // 16. buildAccountSetTx方法回调
void callback_buildOfferCreateTx(std::string, std::string, jingtumlib::Remote *);        // 17. buildOfferCreateSetTx方法回调
void callback_buildOfferCancelTx(std::string, std::string, jingtumlib::Remote *);        // 18. buildOfferCancelTx方法回调
void callback_deployContractTx(std::string, std::string, jingtumlib::Remote *);          // 19. deployContractTx方法回调
void callback_callContractTx(std::string, std::string, jingtumlib::Remote *);            // 20. callContractTx方法回调
void callback_onTransaction(std::string, std::string, jingtumlib::Remote *);             // 21. onTransaction方法回调
void callback_onLedgerClosed(std::string, std::string, jingtumlib::Remote *);            // 21. onLedgerClosed方法回调

void callback_print2(std::string, std::string);  // 一般方法回调显示
void callback_print3(std::string);               // Remote::on方法回调显示

int main()
{	
	/* -------说明：需要测试哪个功能，按照序号范围消除注释，并将其他功能关掉即可---------------*/

	/*---------------------------Wallet 测试-----------------------------------------------*/
	// 1. 生成钱包
	/*jingtumlib::Wallet wallet;
	std::string ss;
	ss = wallet.generate();
	std::cout << ss << std::endl;*/

	// 2. 从私钥生成地址
	/*jingtumlib::Wallet wallet;
	std::string ss;
	ss = wallet.fromSecret("ssyA9qRSmdRUfEppFPy5QdPHZwbgU");
	std::cout << ss << std::endl; */
	
	/*--------------------------------Remote 类测试-----------------------------------------*/
	std::string serverInfo = "{\"server\":\"ws://123.57.219.57:5020\",\"local_sign\":\"true\"}";   // 传入以字符串形式表示的JSON数据
	jingtumlib::Remote remote(serverInfo);  //创建remote对象
	remote.connect(callback_print);  // 3. Remote::connect方法
	//remote.connect(callback_requestServerInfo);  // 4. Remote::requestServerInfo方法
	//remote.connect(callback_requestLedgerClosed);  // 5. Remote::requestLedgerClosed方法
	//remote.connect(callback_requestLedger);  // 6. Remote::requestLedger方法
	//remote.connect(callback_requestTx);  // 7. Remote::requestTx方法
	//remote.connect(callback_requestAccountInfo);  // 8. Remote::requestAccountInfo方法
	//remote.connect(callback_requestAccountTums);  // 9. Remote::requestAccountTums方法
	//remote.connect(callback_requestAccountRelations);  // 10. Remote::requestAccountRelations方法
	//remote.connect(callback_requestAccountOffers);  // 11. Remote::requestAccountOffers方法
	//remote.connect(callback_requestAccountTx);  // 12. Remote::requestAccountTx方法
	//remote.connect(callback_requestOrderBook);  // 13. Remote::requestOrderBook方法
	//remote.connect(callback_buildPaymentTx);  // 14. Remote::buildPaymentTx方法
	//remote.connect(callback_buildRelationTx);  // 15. Remote::buildRelationTx方法
	//remote.connect(callback_buildAccountSetTx);  // 16. Remote::buildAccountSetTx方法
	//remote.connect(callback_buildOfferCreateTx);  // 17. Remote::buildOfferCreateSetTx方法
	//remote.connect(callback_buildOfferCancelTx);  // 18. Remote::buildOfferCancelSetTx方法
	//remote.connect(callback_deployContractTx);  // 19. Remote::deployContractSetTx方法
	//remote.connect(callback_callContractTx);  // 20. Remote::callContractSetTx方法
	//remote.connect(callback_onTransaction);  // 21. Remote::onTransaction方法
	//remote.connect(callback_onLedgerClosed);  // 22. Remote::onLedgerClosed方法

	   	 

}

void callback_print(std::string ex, std::string msg, jingtumlib::Remote *remote) {
	if (ex != "") {
		std::cout << ex << std::endl;
	}
	else {
		std::cout << "result:" << msg << std::endl;	
		remote->disConnect();
	}
	
}

void callback_print2(std::string ex, std::string msg) {
	if (ex != "") {
		std::cout << ex << std::endl;
	}
	else {
		std::cout << "result:" << msg << std::endl;
	}
}

void callback_requestServerInfo(std::string ex, std::string msg, jingtumlib::Remote *remote) {
	if (ex != "") {
		std::cout << ex << std::endl;
	}
	else {
		jingtumlib::Request req = remote->requestServerInfo();
		req.submit(callback_print2);
		//remote->disConnect();
	}
}

void callback_requestLedgerClosed(std::string ex, std::string msg, jingtumlib::Remote *remote) {
	if (ex != "") {
		std::cout << ex << std::endl;
	}
	else {
		jingtumlib::Request req = remote->requestLedgerClosed();
		req.submit(callback_print2);
		//remote->disConnect();
	}
}

void callback_requestLedger(std::string ex, std::string msg, jingtumlib::Remote *remote) {
	if (ex != "") {
		std::cout << ex << std::endl;
	}
	else {
		//jingtumlib::Request req = remote->requestLedger("{}");  // 默认返回最新账本信息
		jingtumlib::Request req = remote->requestLedger("{\"ledger_index\":1000,\"transactions\":\"true\"}");
		req.submit(callback_print2);
		//remote->disConnect();
	}
}

void callback_requestTx(std::string ex, std::string msg, jingtumlib::Remote *remote) {
	if (ex != "") {
		std::cout << ex << std::endl;
	}
	else {
		jingtumlib::Request req = remote->requestTx("{\"hash\":\"B0E15F21E416E2C720E2F5C4FD2B0B9B6A3EA619ADA3461BDB1242D022273336\"}");
		req.submit(callback_print2);
		//remote->disConnect();
	}
}

void callback_requestAccountInfo(std::string ex, std::string msg, jingtumlib::Remote *remote) {
	if (ex != "") {
		std::cout << ex << std::endl;
	}
	else {
		jingtumlib::Request req = remote->requestAccountInfo("{\"account\":\"jDUjqoDZLhzx4DCf6pvSivjkjgtRESY62c\"}");
		req.submit(callback_print2);
		//remote->disConnect();
	}
}

void callback_requestAccountTums(std::string ex, std::string msg, jingtumlib::Remote *remote) {
	if (ex != "") {
		std::cout << ex << std::endl;
	}
	else {
		jingtumlib::Request req = remote->requestAccountTums("{\"account\":\"jDUjqoDZLhzx4DCf6pvSivjkjgtRESY62c\"}");
		req.submit(callback_print2);
		//remote->disConnect();
	}
}

void callback_requestAccountRelations(std::string ex, std::string msg, jingtumlib::Remote *remote) {
	if (ex != "") {
		std::cout << ex << std::endl;
	}
	else {
		jingtumlib::Request req = remote->requestAccountRelations("{\"account\":\"jDUjqoDZLhzx4DCf6pvSivjkjgtRESY62c\",\"type\":\"trust\"}");
		req.submit(callback_print2);
		//remote->disConnect();
	}
}

void callback_requestAccountOffers(std::string ex, std::string msg, jingtumlib::Remote *remote) {
	if (ex != "") {
		std::cout << ex << std::endl;
	}
	else {
		jingtumlib::Request req = remote->requestAccountOffers("{\"account\":\"jDUjqoDZLhzx4DCf6pvSivjkjgtRESY62c\"}");
		req.submit(callback_print2);
		//remote->disConnect();
	}
}

void callback_requestAccountTx(std::string ex, std::string msg, jingtumlib::Remote *remote) {
	if (ex != "") {
		std::cout << ex << std::endl;
	}
	else {
		jingtumlib::Request req = remote->requestAccountTx("{\"account\":\"jS1DsUTZhngqmgvyeEqChw5kF99M6ynaT\"}");
		req.submit(callback_print2);
		//remote->disConnect();
	}
}

void callback_requestOrderBook(std::string ex, std::string msg, jingtumlib::Remote *remote) {
	if (ex != "") {
		std::cout << ex << std::endl;
	}
	else {		
		jingtumlib::Request req = remote->requestOrderBook("{\"gets\":{\"currency\":\"SWT\",\"issuer\":\"\"},\"pays\":{\"currency\":\"CNY\",\"issuer\":\"jBciDE8Q3uJjf111VeiUNM775AMKHEbBLS\"}}");
		req.submit(callback_print2);
		//remote->disConnect();
	}
}

void callback_buildPaymentTx(std::string ex, std::string msg, jingtumlib::Remote *remote) {
	if (ex != "") {
		std::cout << ex << std::endl;
	}
	jingtumlib::Transaction tx = remote->buildPaymentTx("{\"account\":\"jB7rxgh43ncbTX4WeMoeadiGMfmfqY2xLZ\",\"to\":\"jDUjqoDZLhzx4DCf6pvSivjkjgtRESY62c\",\"amount\":{\"value\":0.01,\"currency\":\"SWT\",\"issuer\":\"\"}}");
	std::cout << "tx:" << &tx << std::endl;
	tx.setSecret("sn37nYrQ6KPJvTFmaBYokS3FjXUWd");
	tx.addMemo("给jDUjqoDZLhzx4DCf6pvSivjkjgtRESY62c支付0.01swt.");
	tx.submit(callback_print2);
	//remote->disConnect();
	
}

void callback_buildRelationTx(std::string ex, std::string msg, jingtumlib::Remote *remote) {
	if (ex != "") {
		std::cout << ex << std::endl;
	}
	else {
		std::string options = "{\"account\":\"jB7rxgh43ncbTX4WeMoeadiGMfmfqY2xLZ\",\"target\":\"jDUjqoDZLhzx4DCf6pvSivjkjgtRESY62c\",\"limit\":{\"value\":\"0.01\",\"currency\":\"CCA\",\"issuer\":\"js7M6x28mYDiZVJJtfJ84ydrv2PthY9W9u\"},\"type\":\"authorize\"}";
		jingtumlib::Transaction tx = remote->buildRelationTx(options);
		tx.setSecret("sn37nYrQ6KPJvTFmaBYokS3FjXUWd");
		tx.submit(callback_print2);
		//remote->disConnect();
	}
}

void callback_buildAccountSetTx(std::string ex, std::string msg, jingtumlib::Remote *remote) {
	if (ex != "") {
		std::cout << ex << std::endl;
	}
	else {
		std::string options = "{\"account\":\"jB7rxgh43ncbTX4WeMoeadiGMfmfqY2xLZ\",\"type\":\"property\"}";
		jingtumlib::Transaction tx = remote->buildAccountSetTx(options);
		tx.setSecret("sn37nYrQ6KPJvTFmaBYokS3FjXUWd");
		tx.submit(callback_print2);
		//remote->disConnect();
	}
}

void callback_buildOfferCreateTx(std::string ex, std::string msg, jingtumlib::Remote *remote) {
	if (ex != "") {
		std::cout << ex << std::endl;
	}
	else {
		std::string options = "{\"type\":\"Sell\",\"account\":\"jB7rxgh43ncbTX4WeMoeadiGMfmfqY2xLZ\",\"taker_gets\":{\"value\":\"0.01\",\"currency\":\"CNY\",\"issuer\":\"jBciDE8Q3uJjf111VeiUNM775AMKHEbBLS\"},\"taker_pays\":{\"value\":\"1\",\"currency\":\"SWT\",\"issuer\":\"\"}}";
		jingtumlib::Transaction tx = remote->buildOfferCreateTx(options);
		tx.setSecret("sn37nYrQ6KPJvTFmaBYokS3FjXUWd");
		tx.submit(callback_print2);
		//remote->disConnect();
	}
}

void callback_buildOfferCancelTx(std::string ex, std::string msg, jingtumlib::Remote *remote) {
	if (ex != "") {
		std::cout << ex << std::endl;
	}
	else {
		std::string options = "{\"account\":\"jB7rxgh43ncbTX4WeMoeadiGMfmfqY2xLZ\",\"sequence\":\"2133\"}";
		jingtumlib::Transaction tx = remote->buildOfferCancelTx(options);
		tx.setSecret("sn37nYrQ6KPJvTFmaBYokS3FjXUWd");
		tx.submit(callback_print2);
		//remote->disConnect();
	}
}

void callback_deployContractTx(std::string ex, std::string msg, jingtumlib::Remote *remote) {
	if (ex != "") {
		std::cout << ex << std::endl;
	}
	else {
		std::string options = "{\"account\":\"jB7rxgh43ncbTX4WeMoeadiGMfmfqY2xLZ\",\"amount\":10,\"payload\":\"result={}; function Init(t) result=scGetAccountBalance(t) return result end; function foo(t) result=scGetAccountBalance(t) return end\",\"params\":[\"jB7rxgh43ncbTX4WeMoeadiGMfmfqY2xLZ\"]}";
		jingtumlib::Transaction tx = remote->deployContractTx(options);
		tx.setSecret("sn37nYrQ6KPJvTFmaBYokS3FjXUWd");
		tx.submit(callback_print2);
		//remote->disConnect();
	}
}

void callback_callContractTx(std::string ex, std::string msg, jingtumlib::Remote *remote) {
	if (ex != "") {
		std::cout << ex << std::endl;
	}
	else {
		std::string options = "{\"account\":\"jB7rxgh43ncbTX4WeMoeadiGMfmfqY2xLZ\",\"destination\":\"j4YVQxCxaRRQ6gCVUvi9MoiTfWyPRnHwej\",\"foo\":\"foo\",\"params\":[\"jB7rxgh43ncbTX4WeMoeadiGMfmfqY2xLZ\"]}";
		jingtumlib::Transaction tx = remote->callContractTx(options);
		tx.setSecret("sn37nYrQ6KPJvTFmaBYokS3FjXUWd");
		tx.submit(callback_print2);
		//remote->disConnect();
	}
}

void callback_onTransaction(std::string ex, std::string msg, jingtumlib::Remote *remote) {
	if (ex != "") {
		std::cout << ex << std::endl;
	}
	else {
		remote->on("transaction", callback_print3);
	}
}

void callback_onLedgerClosed(std::string ex, std::string msg, jingtumlib::Remote *remote) {
	if (ex != "") {
		std::cout << ex << std::endl;
	}
	else {
		remote->on("ledger_closed", callback_print3);
	}
}

void callback_print3(std::string msg) {
	std::cout << "msg:" << msg << std::endl;
	
}