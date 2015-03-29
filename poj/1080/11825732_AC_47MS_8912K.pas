var
  s,t,ss:string;
  f:array[0..100,0..100,0..200] of longint;
  n,i,j,k,p,ans:longint;
function max(a,b:longint):longint;
begin
  max:=a;
  if a<b then max:=b;
end;
function d(a,b:char):longint;
begin
  if (a='-')and(b='-') then exit(-1000);
  if a=b then exit(5);
  case a of
    'A':case b of
          'C','T':exit(-1);
          'G':exit(-2);
          '-':exit(-3);
        end;
    'C':case b of
          'A':exit(-1);
          'G':exit(-3);
          'T':exit(-2);
          '-':exit(-4);
        end;
    'G':case b of
          'A','T','-':exit(-2);
          'C':exit(-3);
        end;
    'T':case b of
          'A','-':exit(-1);
          'C','G':exit(-2);
        end;
    '-':case b of
          'A':exit(-3);
          'C':exit(-4);
          'G':exit(-2);
          'T':exit(-1);
        end;
  end;
end;
begin
  readln(n);
  for p:=1 to n do
    begin
      readln(ss);
      s:='';
      for i:=1 to length(ss) do if ss[i] in ['A','C','G','T'] then s:=s+ss[i];
      readln(ss);
      t:='';
      for i:=1 to length(ss) do if ss[i] in ['A','C','G','T'] then t:=t+ss[i];
      fillchar(f,sizeof(f),200);
      f[0,0,0]:=0;
      for i:=0 to length(s) do
        for j:=0 to length(t) do
          if i+j>0 then
            for k:=max(i,j) to i+j do
              begin
                if i=0 then f[i,j,k]:=f[i,j-1,k-1]+d('-',t[j]);
                if j=0 then f[i,j,k]:=f[i-1,j,k-1]+d('-',s[i]);
                if i*j>0 then
                  begin
                    if k-1>=max(i-1,j) then f[i,j,k]:=max(f[i,j,k],f[i-1,j,k-1]+d(s[i],'-'));
                    if k-1>=max(i,j-1) then f[i,j,k]:=max(f[i,j,k],f[i,j-1,k-1]+d(t[j],'-'));
                    if k<=i+j-1 then f[i,j,k]:=max(f[i,j,k],f[i-1,j-1,k-1]+d(s[i],t[j]));
                  end;
              end;
      ans:=-maxlongint;
      for i:=max(length(s),length(t)) to length(s)+length(t) do
        if ans<f[length(s),length(t),i] then ans:=f[length(s),length(t),i];
      writeln(ans);
    end;
end.