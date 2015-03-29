var
  a,b:array[0..9] of longint;
  s,t:string;
  n,i,j,k,p:longint;
function min(a,b:longint):longint;
begin
  min:=a;
  if a>b then min:=b;
end;
begin
  readln(n);
  for p:=1 to n do
    begin
      readln(t);
      s:=copy(t,1,pos(' ',t)-1);
      delete(t,1,pos(' ',t));
      j:=0;
      for i:=1 to 4 do if s[i]=t[i] then inc(j);
      write(j,'A');
      fillchar(a,sizeof(a),0);
      for i:=1 to 4 do inc(a[ord(s[i])-48]);
      fillchar(b,sizeof(b),0);
      for i:=1 to 4 do inc(b[ord(t[i])-48]);
      k:=0;
      for i:=0 to 9 do inc(k,min(a[i],b[i]));
      writeln(k-j,'B');
    end;
end.