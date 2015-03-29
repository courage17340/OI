var
  a,b:array[0..10] of longint;
  s,t:string;
  i,j,n,ans,jw:longint;
begin
  while true do
    begin
      readln(s);
      if s='0 0' then break;
      t:=copy(s,1,pos(' ',s)-1);
      delete(s,1,pos(' ',s));
      fillchar(a,sizeof(a),0);
      fillchar(b,sizeof(b),0);
      for i:=length(s) downto 1 do a[i-length(s)+10]:=ord(s[i])-48;
      for i:=length(t) downto 1 do b[i-length(t)+10]:=ord(t[i])-48;
      ans:=0;
      jw:=0;
      for i:=10 downto 0 do
        begin
          a[i]:=a[i]+b[i]+jw;
          jw:=a[i] div 10;
          inc(ans,jw);
          a[i]:=a[i] mod 10;
        end;
      if ans=0 then writeln('No carry operation.');
      if ans=1 then writeln('1 carry operation.');
      if ans>1 then writeln(ans,' carry operations.');
    end;
end.