var
  a,b,t:int64;
  c:qword;
  k,i:longint;
  s:string;
begin
  readln(a,b);
  s:='';
  if a<b then begin write('-');t:=a;a:=b;b:=t;end;
  c:=a-b;
  str(c,s);
  k:=length(s) mod 3;
  write(copy(s,1,k));
  for i:=k+1 to length(s) do
    begin
      if i mod 3=(k+1) mod 3 then write(',');
      write(s[i]);
    end;
  readln;
end.