/*
 * Copyright (c) 2023 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


#ifndef ASYNCWORKMANAGER_H
#define ASYNCWORKMANAGER_H

#include <list>
#include <mutex>
#include <utility>

#include "js_async_work.h"

class AsyncWorkManager {
public:
    static AsyncWorkManager& GetInstance();
    void AppendAsyncWork(OHOS::ACELite::AsyncWorkHandler work, void* arg);
    void ExecAllAsyncWork();
    void ClearAllAsyncWork();

private:
    AsyncWorkManager() {};
    ~AsyncWorkManager() {};
    std::mutex mutex;
    std::list<std::pair<OHOS::ACELite::AsyncWorkHandler, void*>> workList;
};

#endif // ASYNCWORKMANAGER_H
