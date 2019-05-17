/**
 * Copyright (c) 2017 m2049r
 * <p>
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * <p>
 * http://www.apache.org/licenses/LICENSE-2.0
 * <p>
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <iostream>
#include "monero_wallet_MoneroWalletJni.h"
#include "wallet2.h"
//#include "wallet2_api.h"
//#include "net/http_client.h"



//#include <boost/program_options/options_description.hpp>
//#include <boost/program_options/variables_map.hpp>
//#include <boost/serialization/list.hpp>
//#include <boost/serialization/vector.hpp>
//#include <boost/serialization/deque.hpp>
//#include <boost/thread/lock_guard.hpp>
//#include <atomic>
//#include <random>
//
//#include "include_base_utils.h"
//#include "cryptonote_basic/account.h"
//#include "cryptonote_basic/account_boost_serialization.h"
//#include "cryptonote_basic/cryptonote_basic_impl.h"
//#include "storages/http_abstract_invoke.h"
//#include "rpc/core_rpc_server_commands_defs.h"
//#include "cryptonote_basic/cryptonote_format_utils.h"
//#include "cryptonote_core/cryptonote_tx_utils.h"
//#include "common/unordered_containers_boost_serialization.h"
//#include "common/util.h"
//#include "crypto/chacha.h"
//#include "crypto/hash.h"
//#include "ringct/rctTypes.h"
//#include "ringct/rctOps.h"
//#include "checkpoints/checkpoints.h"
//#include "serialization/pair.h"
//
//#include "wallet_errors.h"
//#include "common/password.h"
////#include "node_rpc_proxy.h"
////#include "message_store.h"
//#include "wallet_light_rpc.h"






//#include "wallet/wallet2.h"
//#include "net/http_client.h"
//#include "version.h"
//#include "net/http_client.h"
//#include <boost/filesystem.hpp>
using namespace std;

//// --------------------------------- LISTENER ---------------------------------
//
//#ifdef __cplusplus
//extern "C"
//{
//#endif
//
//static JavaVM *cachedJVM;
////static jclass class_ArrayList;
//static jclass class_WalletListener;
////static jclass class_TransactionInfo;
////static jclass class_Transfer;
////static jclass class_Ledger;
//
//std::mutex _listenerMutex;
//
//JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *jvm, void *reserved) {
//  cachedJVM = jvm;
//  JNIEnv *jenv;
//  if (jvm->GetEnv(reinterpret_cast<void **>(&jenv), JNI_VERSION_1_6) != JNI_OK) {
//    return -1;
//  }
//
////  class_ArrayList = static_cast<jclass>(jenv->NewGlobalRef(jenv->FindClass("java/util/ArrayList")));
////  class_TransactionInfo = static_cast<jclass>(jenv->NewGlobalRef(jenv->FindClass("com/m2049r/xmrwallet/model/TransactionInfo")));
////  class_Transfer = static_cast<jclass>(jenv->NewGlobalRef(jenv->FindClass("com/m2049r/xmrwallet/model/Transfer")));
//  class_WalletListener = static_cast<jclass>(jenv->NewGlobalRef(jenv->FindClass("monero/wallet/MoneroWalletJni$WalletListenerJni")));
////  class_Ledger = static_cast<jclass>(jenv->NewGlobalRef(jenv->FindClass("com/m2049r/xmrwallet/ledger/Ledger")));
//  return JNI_VERSION_1_6;
//}
//#ifdef __cplusplus
//}
//#endif
//
//int attachJVM(JNIEnv **jenv) {
//  int envStat = cachedJVM->GetEnv((void **) jenv, JNI_VERSION_1_6);
//  if (envStat == JNI_EDETACHED) {
//    if (cachedJVM->AttachCurrentThread((void **) jenv, nullptr) != 0) {
//      return JNI_ERR;
//    }
//  } else if (envStat == JNI_EVERSION) {
//    return JNI_ERR;
//  }
//  return envStat;
//}
//
//void detachJVM(JNIEnv *jenv, int envStat) {
//  if (jenv->ExceptionCheck()) {
//    jenv->ExceptionDescribe();
//  }
//  if (envStat == JNI_EDETACHED) {
//    cachedJVM->DetachCurrentThread();
//  }
//}
//
//struct WalletListenerJni : Bitmonero::WalletListener {
//  jobject jlistener;
//
//  WalletListenerJni(JNIEnv *env, jobject listener) {
//    jlistener = env->NewGlobalRef(listener);
//  }
//
//  ~WalletListenerJni() { };
//
//  void deleteGlobalJavaRef(JNIEnv *env) {
//    std::lock_guard<std::mutex> lock(_listenerMutex);
//    env->DeleteGlobalRef(jlistener);
//    jlistener = nullptr;
//  }
//
//  void updated() {
//    std::lock_guard<std::mutex> lock(_listenerMutex);
//    if (jlistener == nullptr) return;
//    JNIEnv *jenv;
//    int envStat = attachJVM(&jenv);
//    if (envStat == JNI_ERR) return;
//
//    jmethodID listenerClass_updated = jenv->GetMethodID(class_WalletListener, "updated", "()V");
//    jenv->CallVoidMethod(jlistener, listenerClass_updated);
//
//    detachJVM(jenv, envStat);
//  }
//
//  void moneySpent(const std::string &txId, uint64_t amount) {
//    std::lock_guard<std::mutex> lock(_listenerMutex);
//    if (jlistener == nullptr) return;
//  }
//
//  void moneyReceived(const std::string &txId, uint64_t amount) {
//    std::lock_guard<std::mutex> lock(_listenerMutex);
//    if (jlistener == nullptr) return;
//  }
//
//  void unconfirmedMoneyReceived(const std::string &txId, uint64_t amount) {
//    std::lock_guard<std::mutex> lock(_listenerMutex);
//    if (jlistener == nullptr) return;
//  }
//
//  void newBlock(uint64_t height) {
//    std::lock_guard<std::mutex> lock(_listenerMutex);
//    if (jlistener == nullptr) return;
//    JNIEnv *jenv;
//    int envStat = attachJVM(&jenv);
//    if (envStat == JNI_ERR) return;
//
//    jlong h = static_cast<jlong>(height);
//    jmethodID listenerClass_newBlock = jenv->GetMethodID(class_WalletListener, "newBlock", "(J)V");
//    jenv->CallVoidMethod(jlistener, listenerClass_newBlock, h);
//
//    detachJVM(jenv, envStat);
//  }
//
//  void refreshed() {
//    std::lock_guard<std::mutex> lock(_listenerMutex);
//    if (jlistener == nullptr) return;
//    JNIEnv *jenv;
//
//    int envStat = attachJVM(&jenv);
//    if (envStat == JNI_ERR) return;
//
//    jmethodID listenerClass_refreshed = jenv->GetMethodID(class_WalletListener, "refreshed", "()V");
//    jenv->CallVoidMethod(jlistener, listenerClass_refreshed);
//    detachJVM(jenv, envStat);
//  }
//};
////
//////// helper methods
////std::vector<std::string> java2cpp(JNIEnv *env, jobject arrayList) {
////
////    jmethodID java_util_ArrayList_size = env->GetMethodID(class_ArrayList, "size", "()I");
////    jmethodID java_util_ArrayList_get = env->GetMethodID(class_ArrayList, "get",
////                                                         "(I)Ljava/lang/Object;");
////
////    jint len = env->CallIntMethod(arrayList, java_util_ArrayList_size);
////    std::vector<std::string> result;
////    result.reserve(len);
////    for (jint i = 0; i < len; i++) {
////        jstring element = static_cast<jstring>(env->CallObjectMethod(arrayList,
////                                                                     java_util_ArrayList_get, i));
////        const char *pchars = env->GetStringUTFChars(element, NULL);
////        result.emplace_back(pchars);
////        env->ReleaseStringUTFChars(element, pchars);
////        env->DeleteLocalRef(element);
////    }
////    return result;
////}
////
////jobject cpp2java(JNIEnv *env, std::vector<std::string> vector) {
////
////    jmethodID java_util_ArrayList_ = env->GetMethodID(class_ArrayList, "<init>", "(I)V");
////    jmethodID java_util_ArrayList_add = env->GetMethodID(class_ArrayList, "add",
////                                                         "(Ljava/lang/Object;)Z");
////
////    jobject result = env->NewObject(class_ArrayList, java_util_ArrayList_, vector.size());
////    for (std::string &s: vector) {
////        jstring element = env->NewStringUTF(s.c_str());
////        env->CallBooleanMethod(result, java_util_ArrayList_add, element);
////        env->DeleteLocalRef(element);
////    }
////    return result;
////}
////
/////// end helpers
//

#ifdef __cplusplus
extern "C"
{
#endif

// ------------------------------------ STATIC --------------------------------

JNIEXPORT jboolean JNICALL
Java_monero_wallet_MoneroWalletJni_walletExistsJni(JNIEnv *env, jclass clazz, jstring path) {
  cout << "Java_monero_wallet_MoneroWalletJni_walletExistsJni" << endl;
  const char* _path = env->GetStringUTFChars(path, NULL);
  bool keys_file_exists;
  bool wallet_file_exists;
  tools::wallet2::wallet_exists(std::string(_path), keys_file_exists, wallet_file_exists);
  env->ReleaseStringUTFChars(path, _path);
  return static_cast<jboolean>(wallet_file_exists);	// TODO: how is keys file used?

//  try {
//
//  } catch (std::exception e) {
//      cout << "There was a big error" << endl;
//      cout << e.what() << endl;
//      throw e;
//  }

//  try
//  {
//      const char* _path = env->GetStringUTFChars(path, NULL);
//      bool exists = Bitmonero::WalletManagerFactory::getWalletManager()->walletExists(std::string(_path));
//      env->ReleaseStringUTFChars(path, _path);
//      return static_cast<jboolean>(exists);  }
//      catch(const std::runtime_error& re)
//  {
//      // speciffic handling for runtime_error
//      std::cerr << "Runtime error: " << re.what() << std::endl;
//  }
//  catch(const std::exception& ex)
//  {
//      // speciffic handling for all exceptions extending std::exception, except
//      // std::runtime_error which is handled explicitly
//      std::cerr << "Error occurred: " << ex.what() << std::endl;
//  }
//  catch(...)
//  {
//      // catch any other errors (that we have no information about)
//      std::cerr << "Unknown failure occurred. Possible memory corruption" << std::endl;
//  }

  throw std::runtime_error("Not implemented");
}

JNIEXPORT jlong JNICALL
Java_monero_wallet_MoneroWalletJni_openWalletJni(JNIEnv *env, jclass clazz, jstring path, jstring password, jint networkType) {
  cout << "Java_monero_wallet_MoneroWalletJni_openWalletJni" << endl;
  const char* _path = env->GetStringUTFChars(path, NULL);
  const char* _password = env->GetStringUTFChars(password, NULL);
  //Monero::NetworkType _networkType = static_cast<Monero::NetworkType>(networkType);
//
//
//  cout << "Opening wallet!" << endl;
//
//  Bitmonero::WalletManagerFactory::getWalletManager();
  //Bitmonero::Wallet *wallet = Bitmonero::WalletManagerFactory::getWalletManager()->openWallet(std::string(_path), std::string(_password), _networkType);
//
//  cout << "done opening wallet ? " << endl;
//
//  env->ReleaseStringUTFChars(path, _path);
//  env->ReleaseStringUTFChars(password, _password);
//  return reinterpret_cast<jlong>(wallet);





//  const char* _path = env->GetStringUTFChars(path, NULL);
//  const char* _password = env->GetStringUTFChars(password, NULL);
//  //Monero::NetworkType _networkType = static_cast<Monero::NetworkType>(networkType);
//
////  new tools::wallet2(static_cast<cryptonote::network_type>(nettype), kdf_rounds, true)]
//
////  cout << "Starting creation of vm" << endl;
////
////  namespace po = boost::program_options;
////  po::options_description desc("dummy");
////  const command_line::arg_descriptor<std::string, true> arg_password = {"password", "Specifies the password to decrypt the wallet"};
////  const char *argv[4];
////  int argc = 3;
////  argv[0] = "wallet-rpc";
////  argv[1] = "--password";
////  argv[2] = std::string(_password).c_str();
////  argv[3] = NULL;
////  po::variables_map vm;
////  command_line::add_arg(desc, arg_password);
////  po::store(po::parse_command_line(argc, argv, desc), vm);
////
////  //const command_line::arg_descriptor<std::string, true> arg_password = {"password", "Specifies the password to decrypt the wallet"};
////  const auto vmPassword = command_line::get_arg(vm, arg_password);
////  cout << "Stored password: " << vmPassword << endl;
////
////  cout << "Calling make_from_file" << endl;
////  cout << "Path: " + std::string(_path) << endl;
////
////  std::unique_ptr<tools::wallet2> wallet = tools::wallet2::make_from_file(vm, true, std::string(_path), nullptr).first;
////
////  cout << "Ready to return" << endl;
////
////  cout << wallet << endl;
////
////  env->ReleaseStringUTFChars(path, _path);
////  env->ReleaseStringUTFChars(password, _password);
////  //return reinterpret_cast<jlong>(wallet);
//
////  cout << "Defining... " << endl;
////
////  //std::unique_ptr<tools::wallet2> wallet = tools::wallet2::make_from_file(nullptr, true, std::string(_path), nullptr).first;
////
////
//  //tools::wallet2* wallet = new tools::wallet2(static_cast<cryptonote::network_type>(1), 0, true);
//
//  //tools::wallet2 m_wallet;
//  //m_wallet.reset(new tools::wallet2(static_cast<cryptonote::network_type>(-), 1, true))
//
//
//  std::unique_ptr<tools::wallet2> wallet(new tools::wallet2(static_cast<cryptonote::network_type>(2), 1, true));

  //new tools::wallet2(cryptonote::network_type::STAGENET, 1, true);

  //std::unique_ptr<tools::wallet2> wallet;
  //wallet.reset(new tools::wallet2(cryptonote::network_type::STAGENET, 1, true));

//
//  //tools::wallet2 wallet;
//
//  cout << "Creating daemon login" << endl;
//
//  boost::optional<epee::net_utils::http::login> daemon_login{};
//  daemon_login.emplace(std::string("myuser"), std::string("mypassword"));
//
//  cout << "Creating unique pointer..." << endl;
//
//  std::unique_ptr<tools::wallet2> wallet;
//  //wallet(nullptr);
//
//  cout << "Resetting..." << endl;
//
  new tools::wallet2(cryptonote::network_type::STAGENET, 1, true);
//
//
//
//  //wallet.reset();
//
//  ////cout << "Done resetting..." << endl;
//
//
////
////
////  cout << "Loading... " << endl;
////
//  //wallet->load(std::string(_path), std::string(_password));
////
////
////
  //cout << "Seed language: " + wallet->get_seed_language() << endl;

  throw std::runtime_error("Not implemented");
}

JNIEXPORT jlong JNICALL
Java_monero_wallet_MoneroWalletJni_createWalletJni(JNIEnv *env, jclass clazz, jstring language, jint networkType) {
  cout << "Java_monero_wallet_MoneroWalletJni_createWalletJni" << endl;
//  const char *_language = env->GetStringUTFChars(language, NULL);
//  Monero::NetworkType _networkType = static_cast<Monero::NetworkType>(networkType);
//
//  std::unique_ptr<wallet2> wallet = wallet2::make_new(vm2, true, nullptr).first;
//
//  env->ReleaseStringUTFChars(language, _language);
//  return reinterpret_cast<jlong>(wallet);

//  Bitmonero::Wallet *wallet = Bitmonero::WalletManagerFactory::getWalletManager()->createWallet(std::string(_path), std::string(_password), std::string(_language), _networkType);
//
//  env->ReleaseStringUTFChars(path, _path);
//  env->ReleaseStringUTFChars(password, _password);
//  env->ReleaseStringUTFChars(language, _language);
//  return reinterpret_cast<jlong>(wallet);

  throw std::runtime_error("Not implemented");
}

JNIEXPORT jlong JNICALL
Java_monero_wallet_MoneroWalletJni_createWalletFromMnemonicJni(JNIEnv *env, jclass clazz, jint networkType, jstring mnemonic, jint restoreHeight) {
  cout << "Java_monero_wallet_MoneroWalletJni_createWalletFromMnemonicJni" << endl;
//  const char *_mnemonic = env->GetStringUTFChars(mnemonic, NULL);
//  Monero::NetworkType _networkType = static_cast<Monero::NetworkType>(networkType);
//
//  std::string path = std::string("test_wallet_1");
//  std::string password = std::string("supersecretpassword123");
//  Bitmonero::Wallet *wallet = Bitmonero::WalletManagerFactory::getWalletManager()->recoveryWallet(path, password, std::string(_mnemonic), _networkType, (uint64_t) restoreHeight);
//
//  env->ReleaseStringUTFChars(mnemonic, _mnemonic);
//  return reinterpret_cast<jlong>(wallet);

  throw std::runtime_error("Not implemented");
}

JNIEXPORT jlong JNICALL
Java_monero_wallet_MoneroWalletJni_createWalletFromKeysJni(JNIEnv *env, jclass clazz, jstring language, jint networkType, jstring address, jstring viewKey, jstring spendKey, jint restoreHeight) {
  cout << "Java_monero_wallet_MoneroWalletJni_createWalletFromKeysJni" << endl;

//  const char *_language = env->GetStringUTFChars(language, NULL);
//  Monero::NetworkType _networkType = static_cast<Monero::NetworkType>(networkType);
//  const char *_address = env->GetStringUTFChars(address, NULL);
//  const char *_viewKey = env->GetStringUTFChars(viewKey, NULL);
//  const char *_spendKey = env->GetStringUTFChars(spendKey, NULL);
  throw std::runtime_error("Not implemented");

//  Bitmonero::Wallet *wallet = Bitmonero::WalletManagerFactory::getWalletManager()->createWalletFromKeys( std::string(_path), std::string(_password), std::string(_language), _networkType, (uint64_t) restoreHeight, std::string(_address), std::string(_viewKey), std::string(_spendKey));
//
//  env->ReleaseStringUTFChars(path, _path);
//  env->ReleaseStringUTFChars(password, _password);
//  env->ReleaseStringUTFChars(language, _language);
//  env->ReleaseStringUTFChars(address, _address);
//  env->ReleaseStringUTFChars(viewKey, _viewKey);
//  env->ReleaseStringUTFChars(spendKey, _spendKey);
//  return reinterpret_cast<jlong>(wallet);
}

// ----------------------------------- INSTANCE -------------------------------

JNIEXPORT void JNICALL
Java_monero_wallet_MoneroWalletJni_setDaemonConnectionJni(JNIEnv *env, jobject instance, jstring url, jstring username, jstring password) {
  cout << "Java_monero_wallet_MoneroWalletJni_setDaemonConnectionJni" << endl;
  //Bitmonero::Wallet *wallet = getHandle<Bitmonero::Wallet>(env, instance, "walletHandle");
  cout << "Setting daemon connection in c++: " << url << ", " << username << ", " << password << endl;
  //wallet->m_wallet->set_daemon("abcd");
  //wallet->setDaemonLogin("abcd", "abadsf");
  //throw std::runtime_error("Not implemented");
}

JNIEXPORT jstring JNICALL
Java_monero_wallet_MoneroWalletJni_getPathJni(JNIEnv *env, jobject instance) {
  cout << "Java_monero_wallet_MoneroWalletJni_getPathJni" << endl;
  throw std::runtime_error("Not implemented");
  //Bitmonero::Wallet *wallet = getHandle<Bitmonero::Wallet>(env, instance, "walletHandle");
  //return env->NewStringUTF(wallet->path().c_str());
}

JNIEXPORT jint JNICALL
Java_monero_wallet_MoneroWalletJni_getNetworkTypeJni(JNIEnv *env, jobject instance) {
  cout << "Java_monero_wallet_MoneroWalletJni_getNetworkTypeJni" << endl;
  throw std::runtime_error("Not implemented");
  //Bitmonero::Wallet *wallet = getHandle<Bitmonero::Wallet>(env, instance, "walletHandle");
  //return wallet->nettype();
}

JNIEXPORT jstring JNICALL
Java_monero_wallet_MoneroWalletJni_getLanguageJni(JNIEnv *env, jobject instance) {
  cout << "Java_monero_wallet_MoneroWalletJni_getLanguageJni" << endl;
  throw std::runtime_error("Not implemented");
  //Bitmonero::Wallet *wallet = getHandle<Bitmonero::Wallet>(env, instance, "walletHandle");
  //return env->NewStringUTF(wallet->getSeedLanguage().c_str());
}

JNIEXPORT jlong JNICALL
Java_monero_wallet_MoneroWalletJni_getHeightJni(JNIEnv *env, jobject instance) {
  cout << "Java_monero_wallet_MoneroWalletJni_getHeightJni" << endl;
  throw std::runtime_error("Not implemented");
  //return Bitmonero::WalletManagerFactory::getWalletManager()->blockchainHeight();
}

JNIEXPORT jstring JNICALL
Java_monero_wallet_MoneroWalletJni_getMnemonicJni(JNIEnv *env, jobject instance) {
  cout << "Java_monero_wallet_MoneroWalletJni_getMnemonicJni" << endl;
  throw std::runtime_error("Not implemented");
  //Bitmonero::Wallet *wallet = getHandle<Bitmonero::Wallet>(env, instance, "walletHandle");
  //return env->NewStringUTF(wallet->seed().c_str());
}

//JNIEXPORT jstring JNICALL
//Java_monero_wallet_MoneroWalletJni_getBalanceWalletJni(JNIEnv *env, jobject instance) {
//  Bitmonero::Wallet *wallet = getHandle<Bitmonero::Wallet>(env, instance);
//  wallet->balanceAll();
//  std::string balanceStr = "2";	// TODO
//  return env->NewStringUTF(balanceStr.c_str());
//}

JNIEXPORT jstring JNICALL
Java_monero_wallet_MoneroWalletJni_getAddressJni(JNIEnv *env, jobject instance, jint accountIdx, jint subaddressIdx) {
  cout << "Java_monero_wallet_MoneroWalletJni_getAddressJni" << endl;
  throw std::runtime_error("Not implemented");
//  Bitmonero::Wallet *wallet = getHandle<Bitmonero::Wallet>(env, instance, "walletHandle");
//  return env->NewStringUTF(wallet->address((uint32_t) accountIdx, (uint32_t) subaddressIdx).c_str());
}

JNIEXPORT jlong JNICALL
Java_monero_wallet_MoneroWalletJni_setListenerJni(JNIEnv *env, jobject instance, jobject jlistener) {
  cout << "Java_monero_wallet_MoneroWalletJni_setListenerJni" << endl;
  //throw std::runtime_error("Not implemented");
//  Bitmonero::Wallet *wallet = getHandle<Bitmonero::Wallet>(env, instance, "walletHandle");
//
//  // clear old listener
//  wallet->setListener(nullptr);
//  WalletListenerJni *oldListener = getHandle<WalletListenerJni>(env, instance, "listenerHandle");
//  if (oldListener != nullptr) {
//    oldListener->deleteGlobalJavaRef(env);
//    delete oldListener;
//  }
//
//  // set new listener
//  if (jlistener == nullptr) {
//    return 0;
//  } else {
//    WalletListenerJni *listener = new WalletListenerJni(env, jlistener);
//    wallet->setListener(listener);
//    return reinterpret_cast<jlong>(listener);
//  }
}

JNIEXPORT void JNICALL
Java_monero_wallet_MoneroWalletJni_syncJni(JNIEnv *env, jobject instance, jint startHeight) {
  cout << "Java_monero_wallet_MoneroWalletJni_syncJni" << endl;
  throw std::runtime_error("Not implemented");
  //Bitmonero::Wallet *wallet = getHandle<Bitmonero::Wallet>(env, instance, "walletHandle");
  //wallet->refresh();
}

#ifdef __cplusplus
}
#endif
