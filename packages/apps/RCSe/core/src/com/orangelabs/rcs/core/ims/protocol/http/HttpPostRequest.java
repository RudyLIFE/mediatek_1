/*******************************************************************************
 * Software Name : RCS IMS Stack
 *
 * Copyright (C) 2010 France Telecom S.A.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 ******************************************************************************/

package com.orangelabs.rcs.core.ims.protocol.http;



/**
 * HTTP POST request
 * 
 * @author vfml3370
 */
public class HttpPostRequest extends HttpRequest {
	/**
	 * Constructor
	 * 
	 * @param url URL
	 * @param content Content
	 * @param contentType Content type
	 */
	public HttpPostRequest(String url, String content, String contentType) {
		super(url, content, contentType);
	}
	
	/**
	 * Returns the HTTP method
	 * 
	 * @return Method
	 */
	public String getMethod() {
		return "POST";
	}
}
