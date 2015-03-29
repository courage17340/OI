var
  n,ans:longint;
function ok(s:string):boolean;
var i,n:longint;
begin
  n:=length(s);
  for i:=1 to n div 3 do
    if (copy(s,n-i+1,i)=copy(s,n-i-i+1,i))and(copy(s,n-i-i+1,i)=copy(s,n-i-i-i+1,i)) then exit(false);
  exit(true);
end;
procedure search(x:longint;s:string);
begin
  if x=n then if ok(s) then begin inc(ans);exit;end;
  if ok(s) then begin search(x+1,s+'0');search(x+1,s+'1');end;
end;
begin
  read(n);
  ans:=0;
  search(1,'0');
  writeln(ans shl 1);
end.
