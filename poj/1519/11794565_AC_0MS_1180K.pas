var
  s:ansistring;
  t:string;
  i,ans:longint;
begin
  while true do
    begin
	  readln(s);
	  if s='0' then break;
	  ans:=0;
	  for i:=1 to length(s) do
	    ans:=ans+ord(s[i])-48;
	  while ans>=10 do
	    begin
		  str(ans,t);
		  ans:=0;
		  for i:=1 to length(t) do ans:=ans+ord(t[i])-48;
		end;
	  writeln(ans);
	end;
end.